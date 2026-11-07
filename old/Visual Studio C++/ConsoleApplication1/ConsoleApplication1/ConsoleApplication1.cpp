#define NOMINMAX // Эта директива предотвратит переопределение стандартных min и max из windows.h
#include <iostream>
#include <string>
#include <Windows.h>
#include <vector>
#include <sstream>


using namespace std;

class Transport
{
private:
	string manufacturer; // Производитель
	string model; // Модель транспорта
	string typeFuel; // Тип топлива
	string dimension; // Длина Ширина Высота 
	float weight; // Вес
	unsigned int yearOfRelease; // Год изготовления
	float priceTransport; // Цена в руб
	float maxSpeed; // Максимальная скорость
public:
	Transport()
	{
		manufacturer = "";
		model = "";
		typeFuel = "";
		dimension = "";
		weight = 0;
		yearOfRelease = 0;
		priceTransport = 0.0;
		maxSpeed = 0.0;
	}
	Transport(string mf, string m, string tf, string d, float w, unsigned int yor, float pc, float ms)
	{
		manufacturer = mf;
		model = m;
		typeFuel = tf;
		dimension = d;
		weight = w;
		yearOfRelease = yor;
		priceTransport = pc;
		maxSpeed = ms;
	}
	virtual ~Transport() {}
	// SET
	void setManufacturer(string m) {
		manufacturer = m;
	}
	void setModel(string m) {
		model = m;
	}
	void setTypeFuel(string tf) {
		typeFuel = tf;
	}
	void setDimension(string d) {
		dimension = d;
	}
	void setWeight(float w) {
		weight = w;
	}
	void setYearOfRelease(unsigned int yor) {
		yearOfRelease = yor;
	}
	void setPriceTransport(float p) {
		priceTransport = p;
	}
	void setMaxSpeed(float ms) {
		maxSpeed = ms;
	}
	// GET
	string getManufacturer() {
		return manufacturer;
	}
	string getModel() {
		return model;
	}
	string getTypeFuel() {
		return typeFuel;
	}
	string getDimension() {
		return dimension;
	}
	float getWeight() {
		return weight;
	}
	unsigned int getYearOfRelease() {
		return yearOfRelease;
	}
	float getPriceTransport() {
		return priceTransport;
	}
	float getMaxSpeed() {
		return maxSpeed;
	}
	// GET
	//virtual
	//owerride
	virtual void Move() = 0;
	virtual string Start() = 0;
	virtual string Stop() = 0;
};
class Car : public virtual Transport
{
private:
	float fuelConsumption;	  // Расход топлива [литр или  кВт/на 100 км]
	float currentFuelAmount;  // Текущая ёмкость топлива [литры или кВт]
	float maxFuelCapacity;	  // Максимальная ёмкость топлива [литр или кВт]
	float priceFuel92;        // Стоимость литра 92 бензина 
	float priceFuel95;        // Стоимость литра 95 бензина 
	float priceElectricity;   // Стоимость кВт электричества
	bool isStarted;			  // Проверка на возможность заводки автомобиля
public:
	Car() {
		fuelConsumption = 0.0;
		currentFuelAmount = 0.0;
		maxFuelCapacity = 0.0;
		priceFuel92 = 49.78;
		priceFuel95 = 54.69;
		priceElectricity = 2.98;
		isStarted = 0;
	}
	Car(float fcon, float cfa, float mfc, float pf92, float pf95, float pel) {
		fuelConsumption = fcon;
		currentFuelAmount = cfa;
		maxFuelCapacity = mfc;
		priceFuel92 = pf92;
		priceFuel95 = pf95;
		priceElectricity = pel;
		isStarted = 0;
	}
	~Car() override {}
	// SET
	void setFuelConsumption(float fcon) {
		fuelConsumption = fcon;
	}
	void setCurrentFuelAmount(float cfa) {
		currentFuelAmount = cfa;
	}
	void setMaxFuelCapacity(float mfc) {
		maxFuelCapacity = mfc;
	}
	void setPriceFuel_92(float price) {
		priceFuel92 = price;
	}
	void setPriceFuel_95(float price) {
		priceFuel95 = price;
	}
	void setPriceElectricity(float price) {
		priceElectricity = price;
	}
	void setIsStarted(bool start) {
		isStarted = start;
	}
	// GET
	float getFuelConsumption() {
		return fuelConsumption;
	}
	float getCurrentFuelAmount() {
		return currentFuelAmount;
	}
	float getMaxFuelCapacity() {
		return maxFuelCapacity;
	}
	float getPriceFuel_92() {
		return priceFuel92;
	}
	float getPriceFuel_95() {
		return priceFuel95;
	}
	float getPriceElectricity() {
		return priceElectricity;
	}
	bool getIsStarted() {
		return isStarted;
	}
	// METHODS
	float CalculateFuelUsed(float routeLength) { // Расчёт затраченого топлива  [литр или кВт]
		return ((fuelConsumption / 100) * routeLength);
	}
	virtual float PriceOfRefuelingOrCharging() = 0; // Стоимость заправки до полного бака
	virtual void refuelingCar() = 0;
	string Start() override { return ""; }
	string Stop() override { return ""; }
	void Move() override {}

};
class SimpleCar : public Car
{
private:
	bool isFuel95;
public:
	SimpleCar() {
		isFuel95 = false;
	}
	~SimpleCar() override {}
	// SET
	void setIsFuel95(bool choice) {
		isFuel95 = choice;
	}
	// GET
	bool getIsFuel95() {
		return isFuel95;
	}
	// METODI
	float PriceOfRefuelingOrCharging() override // Расчёт стоимости заправки до полного бака 
	{
		if (isFuel95)
			return (((getMaxFuelCapacity() - getCurrentFuelAmount()) * getPriceFuel_95()));
		else
			return (((getMaxFuelCapacity() - getCurrentFuelAmount()) * getPriceFuel_92()));
	}
	void refuelingCar() override // Заправка
	{
		setCurrentFuelAmount(getMaxFuelCapacity());
	}
	string Start() override {
		if (getIsStarted() == false)
		{
			if (getCurrentFuelAmount() <= 3.4)
			{
				setIsStarted(0);
				return "Автомобиль невозможно завести!\n-----НЕТ БЕНЗИНА В БАКЕ-----\n";
			}
			if (getCurrentFuelAmount() <= 4.1 && getCurrentFuelAmount() >= 3.5)
			{
				setIsStarted(1);
				return "Автомобиль был успешно заведен!\n-----КРИТИЧЕСКИЙ НИЗКИЙ УРОВЕНЬ БЕНЗИНА-----\nТекущий уровень бензина: " + to_string(getCurrentFuelAmount()).substr(0, 4) + " литров\n";
			}
			if (getCurrentFuelAmount() >= 4.2)
			{
				setIsStarted(1);
				return "Автомобиль был успешно заведен!\nТекущий уровень бензина: " + to_string(getCurrentFuelAmount()).substr(0, 4) + " литров\n";
			}
		}
		else return "Автомобиль уже заведён!\n";
	}
	string Stop() override {
		if (getIsStarted() == true)
		{
			setIsStarted(0);
			return "Автомобиль был заглушен!\n";
		}
		else return "Автомобиль уже заглушен!\n";
	}
	void Move() override
	{
		cout << "Машина едет\n";
	}
};
class ElectricCar : public Car
{
private:
	float homeCharging;     // Домашняя скорость зарядки (от розетки)
	float standardCharging; // Стандартная скорсоть зарядка от станции Tesla
	float fastCharging;     // Быстрая скорость зарядка от станции Tesla
public:
	ElectricCar() {
		homeCharging = 2.6;
		standardCharging = 7.5;
		fastCharging = 20.5;
	}
	ElectricCar(float hc, float sc, float fc, float ep) {
		homeCharging = hc;
		standardCharging = sc;
		fastCharging = fc;
	}
	~ElectricCar() override {}
	// SET
	void setStandardCharging(float speedCharging) {
		standardCharging = speedCharging;
	}
	void setFastCharging(float speedCharging) {
		fastCharging = speedCharging;
	}
	void setHomeCharging(float speedCharging) {
		homeCharging = speedCharging;
	}
	// GET
	float getStandardCharging() {
		return standardCharging;
	}
	float getFastCharging() {
		return fastCharging;
	}
	float getHomeCharging() {
		return homeCharging;
	}
	// METODI
	string TimeForRefuelingOrCharging(int typeCharging) // Расчёт времни на зарядку электромобиля в секундах
	{
		if (typeCharging == 0) // Домашняя скорость зарядки (от розетки)
		{
			int h = 0, m = 0, s = 0, temp = 0;
			temp = ((getMaxFuelCapacity() - getCurrentFuelAmount()) / (homeCharging / 3600));
			h = temp / 3600;
			temp %= 3600;
			m = temp / 60;
			s = temp % 60;
			string time = to_string(h) + ':' + to_string(m) + ':' + to_string(s);
			return time;
		}
		else if (typeCharging == 1) // Стандартная скорсоть зарядка
		{
			int h = 0, m = 0, s = 0, temp = 0;
			temp = ((getMaxFuelCapacity() - getCurrentFuelAmount()) / (standardCharging / 3600));
			h = temp / 3600;
			temp %= 3600;
			m = temp / 60;
			s = temp % 60;
			string time = to_string(h) + ':' + to_string(m) + ':' + to_string(s);
			return time;
		}
		else if (typeCharging == 2)  // Быстрая скорость зарядка
		{
			int h = 0, m = 0, s = 0, temp = 0;
			temp = ((getMaxFuelCapacity() - getCurrentFuelAmount()) / (fastCharging / 3600));
			h = temp / 3600;
			temp %= 3600;
			m = temp / 60;
			s = temp % 60;
			string time = to_string(h) + ':' + to_string(m) + ':' + to_string(s);
			return time;
		}
	}
	float PriceOfRefuelingOrCharging() override // Расчёт стоимости зарядки батареи до 100%
	{
		return (((getMaxFuelCapacity() - getCurrentFuelAmount()) * getPriceElectricity()));
	}
	void refuelingCar() override // Заправка
	{
		setCurrentFuelAmount(getMaxFuelCapacity());
	}
	string Start() override {
		if (getIsStarted() == false)
		{
			if (getCurrentFuelAmount() <= ((getMaxFuelCapacity() * 15.1) / 100))
			{
				return "Автомобиль невозможно завести!\n-----БАТАРЕЯ РАЗРЯЖЕНА-----\n";
				setIsStarted(0);
			}
			else if ((getCurrentFuelAmount() <= ((getMaxFuelCapacity() * 25.1) / 100)) && (getCurrentFuelAmount() >= ((getMaxFuelCapacity() * 15.2) / 100)))
			{
				setIsStarted(1);
				return "Автомобиль был успешно заведен!\n-----КРИТИЧЕСКИЙ НИЗКИЙ УРОВЕНЬ БАТАРЕИ-----\nТекущий уровень батареи: " + to_string(((100 * getCurrentFuelAmount()) / getMaxFuelCapacity())).substr(0, 5) + "%\n";
			}
			else if (getCurrentFuelAmount() >= ((getMaxFuelCapacity() * 25.2) / 100))
			{
				setIsStarted(1);
				return "Автомобиль был успешно заведен!\nТекущий уровень батареи: " + to_string(((100 * getCurrentFuelAmount()) / getMaxFuelCapacity())).substr(0, 5) + "%\n";
			}
		}
		else return "Автомобиль уже заведён!\n";
	}
	string Stop() override {
		if (getIsStarted() == true)
		{
			setIsStarted(0);
			return "Автомобиль был заглушен!\n";
		}
		else return "Автомобиль уже заглушен!\n";
	}
	void Move() override
	{
		cout << "Электромашина едет\n";
	}
};
class HybridCar : public SimpleCar, public virtual ElectricCar
{
private:
	float rechargBattery; // Подзарядка батареи от двигателяф
public:
	HybridCar()
	{
	}
	HybridCar(float rebat)
	{
		rechargBattery = 0.5;
	}
	~HybridCar() override {}
	// SET
	void setRecargBattery(float rebat) {
		rechargBattery = rebat;
	}
	// GET
	float getRechargBattery() {
		return rechargBattery;
	}
	// METODI
	string Start() override {
		if (SimpleCar::getIsStarted() == false)
		{
			if (SimpleCar::getCurrentFuelAmount() <= 3.4)
			{
				SimpleCar::setIsStarted(0);
				return "Автомобиль невозможно завести!\n-----НЕТ БЕНЗИНА В БАКЕ-----\n";
			}
			if (SimpleCar::getCurrentFuelAmount() <= 4.1 && SimpleCar::getCurrentFuelAmount() >= 3.5)
			{
				SimpleCar::setIsStarted(1);
				return "Автомобиль был успешно заведен!\n-----КРИТИЧЕСКИЙ НИЗКИЙ УРОВЕНЬ БЕНЗИНА-----\nТекущий уровень бензина: " + to_string(SimpleCar::getCurrentFuelAmount()).substr(0, 4) + " литров\nТекущий уровень батареи: " + to_string(((100 * ElectricCar::getCurrentFuelAmount()) / ElectricCar::getMaxFuelCapacity())).substr(0, 5) + "%\n";
			}
			if (SimpleCar::getCurrentFuelAmount() >= 4.2)
			{
				SimpleCar::setIsStarted(1);
				return "Автомобиль был успешно заведен!\nТекущий уровень бензина: " + to_string(SimpleCar::getCurrentFuelAmount()).substr(0, 4) + " литров\nТекущий уровень батареи: " + to_string(((100 * ElectricCar::getCurrentFuelAmount()) / ElectricCar::getMaxFuelCapacity())).substr(0, 5) + "%\n";
			}
		}
		else return "Автомобиль уже заведён!\n";
	}
	string Stop() override {
		if (SimpleCar::getIsStarted() == true)
		{
			SimpleCar::setIsStarted(0);
			return "Автомобиль был заглушен!\n";
		}
		else return "Автомобиль уже заглушен!\n";
	}
	void Move() override
	{

	}
	float PriceOfRefuelingOrCharging() override // Расчёт стоимости заправки до полного бака и зарядки батареи
	{
		if (getIsFuel95())
			return SimpleCar::PriceOfRefuelingOrCharging();
		//return (((getMaxFuelCapacity() - getCurrentFuelAmount()) * getPriceFuel_95()) + ((ElectricCar::getMaxFuelCapacity() - ElectricCar::getCurrentFuelAmount()) * getPriceElectricity()));
		else
			//return (((getMaxFuelCapacity() - getCurrentFuelAmount()) * getPriceFuel_92()));*/
			return 0;
	}
	void RechargingtheBattery() // Зарядка автомобиля
	{

	}
	void refuelingCar() override // Зарядка и зарядка автомобиля
	{
		SimpleCar::setCurrentFuelAmount(SimpleCar::getMaxFuelCapacity());
		ElectricCar::setCurrentFuelAmount(ElectricCar::getMaxFuelCapacity());
	}

};

class SimpleTrain : public Transport
{
private:
	string NameTrain;
	unsigned int PassengerCapacity;
	unsigned int NumberWagons;

public:
	SimpleTrain() {
		NameTrain = "";
		PassengerCapacity = 0;
		NumberWagons = 0;
	}
	SimpleTrain(string model, unsigned int passcap, unsigned int nw) {
		NameTrain = model;
		PassengerCapacity = passcap;
		NumberWagons = nw;
	}
	~SimpleTrain()
	{

	}
	// SET
	void setNameTrain(string model) {
		NameTrain = model;
	}
	void setPassengerCapacity(unsigned int passcap) {
		PassengerCapacity = passcap;
	}
	void setNumberWagons(unsigned int nw) {
		NumberWagons = nw;
	}
	// GET
	string getNameTrain() {
		return NameTrain;
	}
	unsigned int getPassengerCapacity() {
		return PassengerCapacity;
	}
	unsigned int getNumberWagons() {
		return NumberWagons;
	}
	// METODD
	string Start() override {
		return "";
	}
	string Stop() override {
		return "";
	}
	void Move() override {

	}

};
class ExpressTrain : public SimpleTrain
{
private:
	int countSkip;
public:
	ExpressTrain()
	{
		countSkip = 0;
	}
	ExpressTrain(int c)
	{
		countSkip = c;
	}
	~ExpressTrain() {	}
	// SET
	void setCountSkip(int c)
	{
		countSkip = c;
	}
	// GET
	int getCountSkip()
	{
		return countSkip;
	}
	// METODI
	void Move() override
	{

	}
	string Start() override {
		return "";
	}
	string Stop() override {
		return "";
	}
};

class User
{
public:
	void Move(Transport& transport)
	{
		transport.Move();
		//transport->Move(); замена *
	}
};

class Route
{
private:
	string cityName;
	double routeLength;
public:
	Route() {
		cityName = "";
		routeLength = 0;
	}
	Route(string name, double length) {
		cityName = name;
		routeLength = length;
	}
	~Route() {}
	// SET
	void setCityName(string name) {
		cityName = name;
	}
	void setRouteLength(double length) {
		routeLength = length;
	}
	// GET
	string getCityName() {
		return cityName;
	}
	double getRouteLength() {
		return routeLength;
	}
	// METOD
};

// Прототипы функций
int CheckERRORS(string messages, int firstNumberComands, int lastNumberComands);
string CheckERRORS_string(string messages, int lastNumberComands);
double CheckERRORS_double(string messages, double firstNumberComands, double lastNumberComands);
void ShowInfoTransport(Transport* name);
void ShowRefill(Transport* name);
void CreateTransport(Transport* s);
void ShowInfo(string messages);
bool CarIsReady(Transport* name);

int TESTCreateTransport(vector<Transport*>& Tarr);
template <typename T>
void TESTShowInfoTransport(vector<Transport*>& transport)
{
	system("cls");
	for (int i = 0, count = 0; i < transport.size(); i++) {
		if (typeid(*transport[i]) == typeid(T))
		{
			cout << ++count << ". " << transport[i]->getManufacturer() << ' ' << transport[i]->getModel() << endl;
		}
	}

}

int main()
{
	setlocale(LC_ALL, "");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	SimpleCar ToyotaCamry;
	{
		// Инициализация полей Transport
		ToyotaCamry.setManufacturer("Toyota");
		ToyotaCamry.setModel("Camry");
		ToyotaCamry.setTypeFuel("GasOlin");
		ToyotaCamry.setDimension("4885 1840 1445 мм");
		ToyotaCamry.setWeight(1.470);
		ToyotaCamry.setYearOfRelease(2021);
		ToyotaCamry.setPriceTransport(2280625);
		ToyotaCamry.setMaxSpeed(209);
		// Инициализация полей Car
		ToyotaCamry.setFuelConsumption(8.3); // Расход 
		ToyotaCamry.setCurrentFuelAmount(0); // Текущий объём бензина
		ToyotaCamry.setMaxFuelCapacity(60);  // Максимальный объём бака
	}
	ElectricCar TeslaModelS;
	{
		// Инициализация полей Transport
		TeslaModelS.setManufacturer("Tesla");
		TeslaModelS.setModel("ModelS");
		TeslaModelS.setTypeFuel("Electricity");
		TeslaModelS.setDimension("4978 1964 1445 мм");
		TeslaModelS.setYearOfRelease(2021);
		TeslaModelS.setWeight(2.108);
		TeslaModelS.setPriceTransport(7298000);
		TeslaModelS.setMaxSpeed(250);
		// Инициализация полей Car
		TeslaModelS.setFuelConsumption(30);  // Расход 
		TeslaModelS.setCurrentFuelAmount(0); // Текущий уровень батареи
		TeslaModelS.setMaxFuelCapacity(60);  // Максимальная ёмкость батареи
	}
	HybridCar HyundaiLIoniq;
	{
		// Инициализация полей Transport
		HyundaiLIoniq.setManufacturer("Hyundai");
		HyundaiLIoniq.setModel("Ioniq");
		HyundaiLIoniq.setTypeFuel("GasOlin & Electricity");
		HyundaiLIoniq.setDimension("4470 1822 1451 мм");
		HyundaiLIoniq.setWeight(1.390);
		HyundaiLIoniq.setYearOfRelease(2020);
		HyundaiLIoniq.setPriceTransport(2116420);
		HyundaiLIoniq.setMaxSpeed(185);
		// Инициализация полей Car
		HyundaiLIoniq.SimpleCar::setFuelConsumption(3.6);     // Расход
		HyundaiLIoniq.SimpleCar::setCurrentFuelAmount(0);     // Текущий объём бензина
		HyundaiLIoniq.SimpleCar::setMaxFuelCapacity(45);      // Максимальная ёмкость батареи

		HyundaiLIoniq.ElectricCar::setFuelConsumption(14.5);  // Расход
		HyundaiLIoniq.ElectricCar::setCurrentFuelAmount(0);   // Текущий уровень батареи
		HyundaiLIoniq.ElectricCar::setMaxFuelCapacity(38.8);  // Максимальная ёмкость батареи
		/////////////////////////////////////////
	}
	// Ахтунг доделать!!!!!
	SimpleTrain Lastochka;
	{
		Lastochka.setManufacturer("Siemens");
		Lastochka.setModel("ЭС1");
		Lastochka.setTypeFuel("Electricity");
		Lastochka.setDimension("24800 3480 4850 м");
		Lastochka.setYearOfRelease(2011);
		Lastochka.setPriceTransport(120000000);
		Lastochka.setMaxSpeed(160);
		Lastochka.setNameTrain("Ласточка");
		Lastochka.setPassengerCapacity(443);
		Lastochka.setNumberWagons(5);
	}
	ExpressTrain Ivolga;
	{
		Ivolga.setManufacturer("ТВЗ");
		Ivolga.setModel("3.0");
		Ivolga.setTypeFuel("Electricity");
		Ivolga.setDimension("23800 34800 48500 м");
		Ivolga.setYearOfRelease(2022);
		Ivolga.setPriceTransport(0000000);
		Ivolga.setMaxSpeed(140);
		Ivolga.setNameTrain("Иволга");
		Ivolga.setPassengerCapacity(327);
		Ivolga.setNumberWagons(5);
		Ivolga.setCountSkip(5);
	}
	/////////////////////////////////////////
	Route Krasnogorsk;
	{
		Krasnogorsk.setCityName("Красногорск");
		Krasnogorsk.setRouteLength(22.8);
	}
	Route Ramenskoye;
	{
		Ramenskoye.setCityName("Раменское");
		Ramenskoye.setRouteLength(53.3);
	}
	/////////////////////////////////////////
	Route Moscow("Москва", 0);
	Route Moscow3("Москва-3", 0);
	Route Malenkovskyua("Маленковская", 0);
	Route Yauza("Яуза", 0);
	Route Rostokino("Ростокино", 0);
	Route Losinoostrovskyua("Лосиноостровская", 0);
	Route Los("Лось", 0);
	Route Mitishi("Мытищи", 0);
	Route Tarasovskaya("Тарасовская", 0);
	Route Kliyazma("Клязьма", 0);
	Route Pyshkino("Пушкино", 0);
	Route Pravda("Правда", 0);
	Route Sofrino("Софрино", 0);
	Route Hotkovo("Хотьково", 0);
	Route SergyevPosad("Сергиев Посад", 73.3);
	int choice = -1;

	string comands
	{
		"1. Просомтреть информацию о транспорте\n"
		"2. Произвести действия с транспортом\n"
		"3. Добавить новый транспорт\n"
		"4. Удалить транспорт"
	};
	string typeTransport
	{
		"1. Автомобили ДВС\n"
		"2. Электромобиль\n"
		"3. Гибридный автомобиль\n"
		"4. Электричка\n"
		"5. Экспресс электричка"
	};

	string dataBaseScar;
	string dataBaseEcar;
	string dataBaseHcar;
	string dataBaseStrain;
	string dataBaseEtrain;

	int SC_i = 1;
	int EC_i = 1;
	int HC_i = 1;
	int ST_i = 1;
	int ET_i = 1;

	vector<SimpleCar> simpleCar;
	vector<ElectricCar> electricCar;
	vector<HybridCar> hybridCar;
	vector<SimpleTrain> simpleTrain;
	vector<ExpressTrain> expressTrain;

	vector<Transport*> transport;

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	vector<Route> route;
	route.push_back(Krasnogorsk);
	route.push_back(Ramenskoye);
	int Route_i = 2;
	string dataBaseRoute = "1. " + route[0].getCityName() + ' ' + to_string(route[0].getRouteLength()).substr(0, 5) + " км";
	dataBaseRoute += "\n2. " + route[1].getCityName() + ' ' + to_string(route[1].getRouteLength()).substr(0, 5) + " км";

	vector<Route> routeTrain;
	routeTrain.push_back(Moscow);
	routeTrain.push_back(Moscow3);
	routeTrain.push_back(Malenkovskyua);
	routeTrain.push_back(Yauza);
	routeTrain.push_back(Rostokino);
	routeTrain.push_back(Losinoostrovskyua);
	routeTrain.push_back(Los);
	routeTrain.push_back(Mitishi);
	routeTrain.push_back(Tarasovskaya);
	routeTrain.push_back(Kliyazma);
	routeTrain.push_back(Pyshkino);
	routeTrain.push_back(Pravda);
	routeTrain.push_back(Sofrino);
	routeTrain.push_back(Hotkovo);
	routeTrain.push_back(SergyevPosad);
	string dataBaseRouteTrain = "1. " + routeTrain[14].getCityName() + ' ' + to_string(routeTrain[14].getRouteLength()).substr(0, 5);
	int Route_i_train = 15;
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	simpleCar.push_back(ToyotaCamry);
	dataBaseScar += to_string(SC_i) + ". " + simpleCar[0].getManufacturer() + ' ' + simpleCar[0].getModel();
	electricCar.push_back(TeslaModelS);
	dataBaseEcar += to_string(SC_i) + ". " + electricCar[0].getManufacturer() + ' ' + electricCar[0].getModel();
	hybridCar.push_back(HyundaiLIoniq);
	dataBaseHcar += to_string(SC_i) + ". " + hybridCar[0].getManufacturer() + ' ' + hybridCar[0].getModel();
	simpleTrain.push_back(Lastochka);
	dataBaseStrain += to_string(SC_i) + ". " + simpleTrain[0].getNameTrain() + ' ' + simpleTrain[0].getModel();
	expressTrain.push_back(Ivolga);
	dataBaseEtrain += to_string(SC_i) + ". " + expressTrain[0].getNameTrain() + ' ' + expressTrain[0].getModel();

	while (true)
	{
		system("cls");
		cout << "\t /$$$$$$$$  /$$     /$$   /$$$$$$		\n";
		cout << "\t|__  $$__/ | $$    | $$  /$$__  $$		\n";
		cout << "\t   | $$    | $$    | $$ | $$  \\ $$		\n";
		cout << "\t   | $$    |  $$  / $$/ | $$$$$$$$		\n";
		cout << "\t   | $$     \\  $$  $$/  | $$__  $$		\n";
		cout << "\t   | $$      \\  $$$$/   | $$  | $$		\n";
		cout << "\t   | $$       \\  $$/    | $$  | $$		\n";
		cout << "\t   |__/        \\__/     |__/  |__/		\n";

		choice = CheckERRORS("Введите номер команды:\n" + comands, 1, 5);
		switch (choice)
		{
		case 1:
		{
			system("cls");
			int choice1, choice2, choice3 = -1;
			choice1 = CheckERRORS("Выберите вид транспорта: \n1. Автомобили\n2. Электрички \n3. Выйти", 1, 3);
			if (choice1 == 1) ////////////////////////// АВТОМОБИЛИ //////////////////////////
			{
				system("cls");
				choice2 = CheckERRORS("Выберите вид автомобиля: \n1. Авотобили с ДВС\n2. Электромобили \n3. Гибридные автомобили\n4. Выход", 1, 4);
				if (choice2 == 1) // Автомобили с ДВС
				{
					system("cls");
					if (!simpleCar.empty())
					{
						choice3 = CheckERRORS("Введите номер автомобиля:\n" + dataBaseScar, 1, SC_i);
						ShowInfoTransport(&simpleCar[choice3 - 1]);
						break;
					}
					else ShowInfo("Нет автомобилей с ДВС!");
					break;
				}
				if (choice2 == 2) // Электромобили
				{
					system("cls");
					if (!electricCar.empty())
					{
						choice3 = CheckERRORS("Введите номер автомобиля:\n" + dataBaseEcar, 1, EC_i);
						ShowInfoTransport(&electricCar[choice3 - 1]);
						break;
					}
					else ShowInfo("Нет электромобилей!");
					break;
				}
				if (choice2 == 3) // Гибридные автомобили
				{
					if (!hybridCar.empty())
					{
						system("cls");
						choice3 = CheckERRORS("Введите номер автомобиля:\n" + dataBaseHcar, 1, HC_i);
						ShowInfoTransport(&hybridCar[choice3 - 1]);
						break;
					}
					else ShowInfo("Нет гибридних автомобилей!");
					break;
				}
				if (choice2 == 4) break;
				break;
			}
			if (choice1 == 2) ////////////////////////// ЭЛЕКТРИЧКИ //////////////////////////
			{
				system("cls");
				choice2 = CheckERRORS("Выберите вид электрички: \n1. Обычная электричка\n2. Экспресс электричка \n3. Выход", 1, 3);
				if (choice2 == 1) // Обычные электрички
				{
					system("cls");
					if (!simpleTrain.empty())
					{
						choice3 = CheckERRORS("Введите номер электрички:\n" + dataBaseStrain, 1, ST_i);
						ShowInfoTransport(&simpleTrain[choice3 - 1]);
						break;
					}
					else ShowInfo("Нет электричек!");
					break;
				}
				if (choice2 == 2) // Экспресс электрички
				{
					system("cls");
					if (!expressTrain.empty())
					{
						choice3 = CheckERRORS("Введите номер электрички:\n" + dataBaseEtrain, 1, ET_i);
						ShowInfoTransport(&expressTrain[choice3 - 1]);
						break;
					}
					else ShowInfo("Нет экспресс электричек!");
					break;
				}
				if (choice2 == 3) break;
				break;
			}
			if (choice1 == 3) break;
			break;
		}
		case 2:
		{
			system("cls");
			int choice1, choice2, choice3, choice4, choice_route;
			double choice_speed;
			// Выбор типа транспорта
			choice1 = CheckERRORS("Выберите вид транспорта: \n1. Автомобили\n2. Электрички \n3. Выйти", 1, 3);
			if (choice1 == 1) ////////////////////////// АВТОМОБИЛИ //////////////////////////
			{
				system("cls");
				choice2 = CheckERRORS("Выберите вид автомобиля: \n1. Авотобили с ДВС\n2. Электромобили \n3. Гибридные автомобили\n4. Выход", 1, 4);
				// Автомобили с ДВС
				if (choice2 == 1)
				{
					system("cls");
					// Выбор команды для автомобилей с ДВС
					choice3 = CheckERRORS("Выберите номер команды:\n1. Завести автомобиль\n2. Заглушить автомобиль\n3. Заправить автомобиль\n4. Отправиться в путь\n5. Выйти", 1, 5);
					if (choice3 == 1)
					{
						system("cls");
						// Выбор конкретного экземпляра класса SimpleCar
						choice4 = CheckERRORS("Введите номер автомобиля:\n" + dataBaseScar, 1, SC_i);
						system("cls");
						cout << simpleCar[choice4 - 1].Start();
						system("pause");
						break;
					}
					if (choice3 == 2)
					{
						system("cls");
						// Выбор конкретного экземпляра класса SimpleCar
						choice4 = CheckERRORS("Введите номер автомобиля:\n" + dataBaseScar, 1, SC_i);
						system("cls");
						cout << simpleCar[choice4 - 1].Stop();
						system("pause");
						break;
					}
					if (choice3 == 3)
					{
						system("cls");
						// Выбор конкретного экземпляра класса SimpleCar
						choice4 = CheckERRORS("Введите номер автомобиля:\n" + dataBaseScar, 1, SC_i);
						ShowRefill(&simpleCar[choice4 - 1]);
						//ShowRefill(&ToyotaCamry);
						break;
					}
					if (choice3 == 4)
					{
						system("cls");
						// Выбор пункта назначения из экземпляра класса Route
						choice_route = CheckERRORS("Выберите маршрут:\n" + dataBaseRoute, 1, Route_i);
						// Выбор конкретного экземпляра класса SimpleCar
						choice4 = CheckERRORS("Введите номер автомобиля:\n" + dataBaseScar, 1, SC_i);
						// Выбор скорости экземпляра класса SimpleCar
						choice_speed = CheckERRORS_double("Выберите с какой скоростью будете ехать (от 10 до << " + to_string(simpleCar[choice4 - 1].getMaxSpeed()).substr(0, 5) + " ):", 9, simpleCar[choice4 - 1].getMaxSpeed() + 1);

						if (CarIsReady(&simpleCar[choice4 - 1]))
						{
							int timeMax = route[choice_route - 1].getRouteLength();
							string route_save;
							system("cls");
							cout << "Начальный уровень безина: " << simpleCar[choice4 - 1].getCurrentFuelAmount() << endl;
							cout << "Поехали!\nПрогресс: ";
							cout << "[ 0,000 км ";
							int count_f = 0;
							int count = 0;
							while (count <= 29)
							{
								Sleep(timeMax * 10 - choice_speed);
								cout << ".";
								route_save += ".";
								count++;
								if (count - count_f == 5)
								{
									cout << ' ';
									cout << to_string((route[choice_route - 1].getRouteLength() / 30) * count).substr(0, 5);
									cout << " км ";
									route_save += ' ' + to_string((route[choice_route - 1].getRouteLength() / 30) * count).substr(0, 5) + " км ";
									count_f = count;
								}
								simpleCar[choice4 - 1].setCurrentFuelAmount(simpleCar[choice4 - 1].getCurrentFuelAmount() - ((simpleCar[choice4 - 1].getFuelConsumption() / 100) * (route[choice_route - 1].getRouteLength() / 30)));
								if ((simpleCar[choice4 - 1].getCurrentFuelAmount() <= 4) && 3 >= (simpleCar[choice4 - 1].getCurrentFuelAmount() - ((simpleCar[choice4 - 1].getFuelConsumption() / 100) * (route[choice_route - 1].getRouteLength() / 30 - count))))
								{
									system("cls");
									cout << "ВНИМАНИЕ!\nБензина осталось меньше 4 литров!\nНеобходимо заправится!\n";
									system("pause");
									ShowRefill(&simpleCar[choice4 - 1]);
									system("cls");
									cout << simpleCar[choice4 - 1].getCurrentFuelAmount() << endl;
									cout << "Продолжим путь!\nПрогресс: ";
									cout << "[" + route_save;
								}
							}
							cout << "]\nПриехали\n";
							cout << "Город: " << route[choice_route - 1].getCityName() << " \n";
							cout << "Осталось бензина: " << simpleCar[choice4 - 1].getCurrentFuelAmount() << endl;
							system("pause");
							system("cls");
							if (simpleCar[choice4 - 1].getCurrentFuelAmount() <= 4.1)
							{
								system("cls");
								int choiceYN;
								choiceYN = CheckERRORS("Похоже у вас осталось меньше 5 литров бензина\nХотите заправится (1-да/2-нет)", 1, 2);
								if (choiceYN == 1) ShowRefill(&simpleCar[choice4 - 1]);
								else
								{
									cout << "Хорошо, но не забудьте заправится потом)\n";
									system("pause");
								}
							}
							break;
						}
					}
					if (choice3 == 5) break;
					break;
				}
				// Электромобили
				if (choice2 == 2)
				{
					system("cls");
					// Выбор команды для электромобилей
					choice3 = CheckERRORS("Выберите номер команды:\n1. Завести автомобиль\n2. Заглушить автомобиль\n3. Зарядить автомобиль\n4. Отправиться в путь\n5. Выйти", 1, 5);
					if (choice3 == 1)
					{
						system("cls");
						// Выбор конкретного экземпляра класса ElectricCar
						choice4 = CheckERRORS("Введите номер автомобиля:\n" + dataBaseEcar, 1, EC_i);
						system("cls");
						cout << electricCar[choice4 - 1].Start();
						system("pause");
						break;
					}
					if (choice3 == 2)
					{
						system("cls");
						// Выбор конкретного экземпляра класса ElectricCar
						choice4 = CheckERRORS("Введите номер автомобиля:\n" + dataBaseEcar, 1, EC_i);
						system("cls");
						cout << electricCar[choice4 - 1].Stop();
						system("pause");
						break;
					}
					if (choice3 == 3)
					{
						system("cls");
						// Выбор конкретного экземпляра класса ElectricCar
						choice4 = CheckERRORS("Введите номер автомобиля:\n" + dataBaseEcar, 1, EC_i);
						ShowRefill(&electricCar[choice4 - 1]);
					}
					if (choice3 == 4)
					{
						system("cls");
						// Выбор пункта назначения из экземпляра класса Route
						choice_route = CheckERRORS("Выберите маршрут:\n" + dataBaseRoute, 1, Route_i);
						// Выбор конкретного экземпляра класса ElectricCar
						choice4 = CheckERRORS("Введите номер автомобиля:\n" + dataBaseEcar, 1, EC_i);
						// Выбор скорости экземпляра класса ElectricCar
						choice_speed = CheckERRORS_double("Выберите с какой скоростью будете ехать (от 10 до << " + to_string(electricCar[choice4 - 1].getMaxSpeed()).substr(0, 5) + " ):", 9, electricCar[choice4 - 1].getMaxSpeed() + 1);

						if (CarIsReady(&electricCar[choice4 - 1]))
						{
							int timeMax = route[choice_route - 1].getRouteLength();
							string route_save;
							system("cls");
							//to_string(((100 * getCurrentFuelAmount()) / getMaxFuelCapacity())).substr(0, 5) + "%\n"
							cout << "Начальный уровень батареи: " << (100 * electricCar[choice4 - 1].getCurrentFuelAmount() / electricCar[choice4 - 1].getMaxFuelCapacity()) << " %\n";
							cout << "Поехали!\nПрогресс: ";
							cout << "[ 0,000 км ";
							int count_f = 0;
							int count = 0;
							while (count <= 29)
							{
								Sleep(timeMax * 10 - choice_speed);
								cout << ".";
								route_save += ".";
								count++;
								if (count - count_f == 5)
								{
									cout << ' ';
									cout << to_string((route[choice_route - 1].getRouteLength() / 30) * count).substr(0, 5);
									cout << " км ";
									route_save += ' ' + to_string((route[choice_route - 1].getRouteLength() / 30) * count).substr(0, 5) + " км ";
									count_f = count;
								}
								electricCar[choice4 - 1].setCurrentFuelAmount(electricCar[choice4 - 1].getCurrentFuelAmount() - ((electricCar[choice4 - 1].getFuelConsumption() / 100) * (route[choice_route - 1].getRouteLength() / 30)));
								if (((100 * electricCar[choice4 - 1].getCurrentFuelAmount() / electricCar[choice4 - 1].getMaxFuelCapacity()) <= 25.2) || 7 >= (electricCar[choice4 - 1].getCurrentFuelAmount() - ((electricCar[choice4 - 1].getFuelConsumption() / 100) * (route[choice_route - 1].getRouteLength() / 30))))
								{
									system("cls");
									cout << "ВНИМАНИЕ!\nВ батареи осталось меньше 20% заряда!\nНеобходимо зарядка!\n";
									system("pause");
									ShowRefill(&electricCar[choice4 - 1]);
									system("cls");
									cout << electricCar[choice4 - 1].getCurrentFuelAmount() << endl;
									cout << "Продолжим путь!\nПрогресс: ";
									cout << "[" + route_save;
								}
							}
							cout << "]\nПриехали\n";
							cout << "Город: " << route[choice_route - 1].getCityName() << " \n";
							cout << "Уровень батареи: " << (100 * electricCar[choice4 - 1].getCurrentFuelAmount() / electricCar[choice4 - 1].getMaxFuelCapacity()) << " %\n";
							system("pause");
							system("cls");
							if (electricCar[choice4 - 1].getCurrentFuelAmount() <= 4.1)
							{
								system("cls");
								int choiceYN;
								choiceYN = CheckERRORS("Похоже у вас осталось меньше 5 литров бензина\nХотите заправится (1-да/2-нет)", 1, 2);
								if (choiceYN == 1) ShowRefill(&electricCar[choice4 - 1]);
								else
								{
									cout << "Хорошо, но не забудьте заправится потом)\n";
									system("pause");
								}
							}
							break;
						}
					}
					if (choice3 == 5) break;
					break;
				}
				// Гибридные автомобили
				if (choice2 == 3)
				{
					system("cls");
					// Выбор команды для автомобилей с ДВС
					choice3 = CheckERRORS("Выберите номер команды:\n1. Завести автомобиль\n2. Заглушить автомобиль\n3. Заправить и зарядить автомобиль\n4. Отправиться в путь\n5. Выйти", 1, 5);
					if (choice3 == 1)
					{
						system("cls");
						// Выбор конкретного экземпляра класса HybridCar
						choice4 = CheckERRORS("Введите номер автомобиля:\n" + dataBaseHcar, 1, HC_i);
						system("cls");
						cout << hybridCar[choice4 - 1].Start();
						system("pause");
					}
					if (choice3 == 2)
					{
						system("cls");
						// Выбор конкретного экземпляра класса HybridCar
						choice4 = CheckERRORS("Введите номер автомобиля:\n" + dataBaseHcar, 1, HC_i);
						system("cls");
						cout << hybridCar[choice4 - 1].Stop();
						system("pause");
					}
					if (choice3 == 3)
					{
						system("cls");
						// Выбор конкретного экземпляра класса HybridCar
						choice4 = CheckERRORS("Введите номер автомобиля:\n" + dataBaseHcar, 1, HC_i);
						ShowRefill(&hybridCar[choice4 - 1]);
					}
					if (choice3 == 4)
					{
						system("cls");
						// Выбор пункта назначения из экземпляра класса Route
						choice_route = CheckERRORS("Выберите маршрут:\n" + dataBaseRoute, 1, Route_i);
						// Выбор конкретного экземпляра класса SimpleCar
						choice4 = CheckERRORS("Введите номер автомобиля:\n" + dataBaseHcar, 1, HC_i);
						// Выбор скорости экземпляра класса SimpleCar
						choice_speed = CheckERRORS_double("Выберите с какой скоростью будете ехать (от 10 до << " + to_string(hybridCar[choice4 - 1].getMaxSpeed()).substr(0, 5) + " ):", 9, hybridCar[choice4 - 1].getMaxSpeed() + 1);

						if (CarIsReady(&hybridCar[choice4 - 1]))
						{
							int timeMax = route[choice_route - 1].getRouteLength();
							string route_save;
							system("cls");
							cout << "Начальный уровень безина: " << hybridCar[choice4 - 1].SimpleCar::getCurrentFuelAmount() << endl;
							cout << "Начальный уровень батареи: " << (hybridCar[choice4 - 1].ElectricCar::getCurrentFuelAmount() * 100) / hybridCar[choice4 - 1].ElectricCar::getMaxFuelCapacity() << " %\n";
							cout << "Поехали!\nПрогресс: ";
							cout << "[ 0,000 км ";
							int count_f = 0;
							int count = 0;
							while (count <= 29)
							{
								Sleep(timeMax * 10 - choice_speed);
								cout << ".";
								route_save += ".";
								count++;
								if (count - count_f == 5)
								{
									cout << ' ';
									cout << to_string((route[choice_route - 1].getRouteLength() / 30) * count).substr(0, 5);
									cout << " км ";
									route_save += ' ' + to_string((route[choice_route - 1].getRouteLength() / 30) * count).substr(0, 5) + " км ";
									count_f = count;
								}
								// Если батарея больше 20%
								if (20 >= ((hybridCar[choice4 - 1].ElectricCar::getCurrentFuelAmount() * 20) / hybridCar[choice4 - 1].ElectricCar::getMaxFuelCapacity()))
								{
									hybridCar[choice4 - 1].SimpleCar::setCurrentFuelAmount(hybridCar[choice4 - 1].SimpleCar::getCurrentFuelAmount() - (((hybridCar[choice4 - 1].SimpleCar::getFuelConsumption() / 100) * (route[choice_route - 1].getRouteLength() / 30)) / 2));
									hybridCar[choice4 - 1].ElectricCar::setCurrentFuelAmount(hybridCar[choice4 - 1].ElectricCar::getCurrentFuelAmount() - (((hybridCar[choice4 - 1].ElectricCar::getFuelConsumption() / 100) * (route[choice_route - 1].getRouteLength() / 30)) / 2));
								}
								else  // Режим подзарядки батареи
								{
									hybridCar[choice4 - 1].SimpleCar::setCurrentFuelAmount(hybridCar[choice4 - 1].SimpleCar::getCurrentFuelAmount() - (((hybridCar[choice4 - 1].SimpleCar::getFuelConsumption() / 100) * (route[choice_route - 1].getRouteLength() / 30))));
									if (hybridCar[choice4 - 1].ElectricCar::getCurrentFuelAmount() + (hybridCar[choice4 - 1].getRechargBattery() * (route[choice_route - 1].getRouteLength() / 30)) < hybridCar[choice4 - 1].ElectricCar::getMaxFuelCapacity())
										hybridCar[choice4 - 1].ElectricCar::setCurrentFuelAmount(hybridCar[choice4 - 1].ElectricCar::getCurrentFuelAmount() + (hybridCar[choice4 - 1].getRechargBattery() * (route[choice_route - 1].getRouteLength() / 30)));
									else
										hybridCar[choice4 - 1].ElectricCar::setCurrentFuelAmount(hybridCar[choice4 - 1].ElectricCar::getMaxFuelCapacity());

								}
								if ((hybridCar[choice4 - 1].SimpleCar::getCurrentFuelAmount() <= 4) && 3 >= (hybridCar[choice4 - 1].SimpleCar::getCurrentFuelAmount() - ((hybridCar[choice4 - 1].SimpleCar::getFuelConsumption() / 100) * (route[choice_route - 1].getRouteLength() / 30 - count))))
								{
									system("cls");
									cout << "ВНИМАНИЕ!\nБензина осталось меньше 4 литров!\nНеобходимо заправится!\n";
									system("pause");
									ShowRefill(&hybridCar[choice4 - 1]);
									system("cls");
									cout << hybridCar[choice4 - 1].SimpleCar::getCurrentFuelAmount() << endl;
									cout << "Продолжим путь!\nПрогресс: ";
									cout << "[" + route_save;
								}
							}
							cout << "]\nПриехали\n";
							cout << "Город: " << route[choice_route - 1].getCityName() << " \n";
							cout << "Осталось бензина: " << hybridCar[choice4 - 1].SimpleCar::getCurrentFuelAmount() << endl;
							cout << "Уровень батареи: " << (hybridCar[choice4 - 1].ElectricCar::getCurrentFuelAmount() * 100) / hybridCar[choice4 - 1].ElectricCar::getMaxFuelCapacity() << " %\n";
							system("pause");
							system("cls");
							if (hybridCar[choice4 - 1].SimpleCar::getCurrentFuelAmount() <= 4.1)
							{
								system("cls");
								int choiceYN;
								choiceYN = CheckERRORS("Похоже у вас осталось меньше 5 литров бензина\nХотите заправится (1-да/2-нет)", 1, 2);
								if (choiceYN == 1) ShowRefill(&hybridCar[choice4 - 1]);
								else
								{
									cout << "Хорошо, но не забудьте заправится потом)\n";
									system("pause");
								}
							}
							break;
						}
					}
					if (choice3 == 5) break;
					break;
				}
				// Выход
				if (choice2 == 4) break;
				break;
			}
			if (choice1 == 2) ////////////////////////// ЭЛЕКТРИЧКИ //////////////////////////
			{
				int tiket = -1;
				system("cls");
				// Выбор команды для обычных электричек
				choice2 = CheckERRORS("Выберите вид электрички: \n1.Обычная электричка\n2.Экспресс электричка\n3.Выйти", 1, 3);
				if (choice2 == 1)
				{
					choice3 = CheckERRORS("Выберите номер команды:\n1. Отправиться в путь\n2. Выйти", 1, 3);
					if (choice3 == 1)
					{
						system("cls");
						choice_route = CheckERRORS("Выберите маршрут:\n" + dataBaseRouteTrain, 1, Route_i_train);
						choice4 = CheckERRORS("Введите номер электрички:\n" + dataBaseStrain, 1, ST_i);
						choice_speed = simpleTrain[choice4 - 1].getMaxSpeed() / 2;
						int timeMax = routeTrain[choice_route - 1].getRouteLength();
						string route_save = routeTrain[0].getCityName() + ' ';
						int countCity = 0;
						system("cls");
						cout << "Электричка отправляется со станции " << routeTrain[0].getCityName() << ". \n";
						cout << "Слудующая остановка: " << routeTrain[countCity + 1].getCityName();
						cout << "\nОСТОРОЖНО ДВЕРИ ЗАКРВЫВАЮТСЯ:\n";
						Sleep(8000);
						system("cls");
						cout << "Прогресс: [ " + routeTrain[countCity].getCityName() + ' '; countCity++;
						int count_f = 0;
						int count = 0;
						while (count <= 55)
						{
							Sleep(simpleTrain[choice4 - 1].getMaxSpeed() + 800);
							cout << ".";
							route_save += '.';
							count++;
							if (count - count_f == 4 && countCity != Route_i_train)
							{

								cout << ' ' + routeTrain[countCity].getCityName() + ' ';
								route_save += ' ' + routeTrain[countCity].getCityName() + ' ';
								countCity++;
								count_f = count;
								cout << "\nСлудующая остановка: " << routeTrain[countCity].getCityName();
								cout << "\nОСТОРОЖНО ДВЕРИ ЗАКРВЫВАЮТСЯ:\n";
								Sleep(3000);
								system("cls");
								cout << "Прогресс: [ " + route_save;
							}
						}
						cout << " ]\nЭлектричка прибыла на станцию " << routeTrain[Route_i_train - 1].getCityName() << " Приехали\n";
						system("pause");
						system("cls");
						break;
					}
					if (choice3 == 2) break;
					break;
				}
				if (choice2 == 2)
				{
					system("cls");
					choice3 = CheckERRORS("Выберите номер команды:\n1. Отправиться в путь\n2. Выйти", 1, 3);
					if (choice3 == 1)
					{
						system("cls");
						choice_route = CheckERRORS("Выберите маршрут:\n" + dataBaseRouteTrain, 1, Route_i_train);
						choice4 = CheckERRORS("Введите номер электрички:\n" + dataBaseEtrain, 1, ET_i);
						choice_speed = expressTrain[choice4 - 1].getMaxSpeed() / 2;
						int timeMax = routeTrain[choice_route - 1].getRouteLength();
						string route_save = routeTrain[0].getCityName() + ' ';
						int countCity = 0;
						system("cls");
						cout << "Электричка отправляется со станции " << routeTrain[0].getCityName() << ". \n";
						cout << "Слудующая остановка: " << routeTrain[countCity + 1].getCityName();
						cout << "\nОСТОРОЖНО ДВЕРИ ЗАКРВЫВАЮТСЯ:\n";
						Sleep(8000);
						system("cls");
						cout << "Прогресс: [ " + routeTrain[countCity].getCityName() + ' '; countCity++;
						int count_f = 0;
						int count = 0;
						while (count <= 56)
						{

							Sleep(simpleTrain[choice4 - 1].getMaxSpeed() + 350);
							cout << ".";
							route_save += '.';
							count++;
							if (count - count_f == 4 && countCity != Route_i_train)
							{

								cout << ' ' + routeTrain[countCity].getCityName() + ' ';
								route_save += ' ' + routeTrain[countCity].getCityName() + ' ';
								countCity++;
								count_f = count;
								cout << "\nСлудующая остановка: " << routeTrain[countCity].getCityName();
								cout << "\nОСТОРОЖНО ДВЕРИ ЗАКРВЫВАЮТСЯ:\n";
								Sleep(3000);
								system("cls");
								cout << "Прогресс: [ " + route_save;
							}
							if (countCity == 14 && count == 55)
							{
								cout << ". " << routeTrain[14].getCityName();
								break;
							}
						}
						cout << " ]\nЭлектричка прибыла на станцию " << routeTrain[14].getCityName() << ". \n";
						system("pause");
						system("cls");
						break;
					}
					if (choice3 == 2) break;
					break;
				}
				if (choice2 == 3) break;
				break;
			}
			if (choice1 == 3) ////////////////////////// ВЫХОД //////////////////////////
			{
				break;
			}
			break;
		}
		case 3:
		{
			system("cls");
			int choice2; // Выбор типа трансорта
			choice2 = CheckERRORS("Выберите тип трансопрта который хотите добвить:\n" + typeTransport + "\n6. Выйти", 1, 6);
			if (choice2 == 1) // Автомобили с ДВС
			{
				if (SC_i <= 49)
				{
					transport.push_back(new SimpleCar());
					TESTCreateTransport(transport);
					SC_i++;
					dataBaseScar += '\n' + to_string(SC_i) + ". " + transport[0]->getManufacturer() + ' ' + transport[0]->getModel();
					simpleCar.push_back(*dynamic_cast<SimpleCar*>(transport[0]));
					transport.clear();
					break;
				}
				else ShowInfo("Создано максимальное количество автомобилей с ДВС");
				break;
			}
			if (choice2 == 2) // Электромобили
			{
				if (EC_i <= 49)
				{
					transport.push_back(new ElectricCar());
					TESTCreateTransport(transport);
					EC_i++;
					dataBaseEcar += '\n' + to_string(EC_i) + ". " + transport[0]->getManufacturer() + ' ' + transport[0]->getModel();
					electricCar.push_back(*dynamic_cast<ElectricCar*>(transport[0]));
					transport.clear();
					break;
				}
				else ShowInfo("Создано максимальное количество электромобилей");
				break;
			}
			if (choice2 == 3) // Гибридные автомобили
			{
				if (HC_i <= 49)
				{
					transport.push_back(new HybridCar());
					TESTCreateTransport(transport);
					HC_i++;
					dataBaseHcar += '\n' + to_string(HC_i) + ". " + transport[0]->getManufacturer() + ' ' + transport[0]->getModel();
					hybridCar.push_back(*dynamic_cast<HybridCar*>(transport[0]));
					transport.clear();
					break;
				}
				else ShowInfo("Создано максимальное количество гибридных автомобилей");
				break;
			}
			if (choice2 == 4) // Электрички
			{
				if (ST_i <= 49)
				{
					transport.push_back(new SimpleTrain());
					TESTCreateTransport(transport);
					ST_i++;
					SimpleTrain Strain = *dynamic_cast<SimpleTrain*>(transport[0]);
					dataBaseStrain += '\n' + to_string(ST_i) + ". " + Strain.getNameTrain() + ' ' + transport[0]->getModel();
					simpleTrain.push_back(*dynamic_cast<SimpleTrain*>(transport[0]));
					transport.clear();
					break;
				}
				else ShowInfo("Создано максимальное количество электричек");
			}
			if (choice2 == 5) // Экспресс электрички
			{
				if (ET_i <= 49)
				{
					transport.push_back(new ExpressTrain());
					TESTCreateTransport(transport);
					ET_i++;
					ExpressTrain Etrain = *dynamic_cast<ExpressTrain*>(transport[0]);
					dataBaseEtrain += '\n' + to_string(ET_i) + ". " + Etrain.getNameTrain() + ' ' + transport[0]->getModel();
					expressTrain.push_back(*dynamic_cast<ExpressTrain*>(transport[0]));
					transport.clear();
					break;
				}
				else ShowInfo("Создано максимальное количество экспресс электричек");
			}
			if (choice2 == 6) break;
			break;
		}
		case 4:
		{
			system("cls");
			int choice1, choice2, choice3;
			choice1 = CheckERRORS("Выберите вид транспорта: \n1. Машины\n2. Электрички \n3. Выйти", 1, 3);
			if (choice1 == 1) ////////////////////////// АВТОМОБИЛИ //////////////////////////
			{
				system("cls");
				choice2 = CheckERRORS("Выберите вид автомобиля: \n1. Авотобили с ДВС\n2. Электромобили \n3. Гибридные автомобили\n4. Выход", 1, 4);
				if (choice2 == 1)
				{
					if (!simpleCar.empty()) // Автомобили с ВДС
					{
						system("cls");
						choice3 = CheckERRORS("Введите номер автомобиля:\n" + dataBaseScar, 1, SC_i);
						simpleCar.erase(simpleCar.begin() + (choice3 - 1));
						dataBaseScar.clear();
						SC_i--;
						for (int i = 0; i < simpleCar.size(); i++)
						{
							dataBaseScar += (to_string(i + 1) + ". " + simpleCar[i].getManufacturer() + ' ' + simpleCar[i].getModel() + '\n');
						}
						break;
					}
					else
					{
						system("cls");
						cout << "Нет автомобилей с ДВС!\n";
						system("pause");
					}
					break;
				}
				if (choice2 == 2) // Электромобили
				{
					if (!electricCar.empty())
					{
						system("cls");
						choice3 = CheckERRORS("Введите номер автомобиля:\n" + dataBaseEcar, 1, EC_i);
						electricCar.erase(electricCar.begin() + (choice3 - 1));
						dataBaseEcar.clear();
						EC_i--;
						for (int i = 0; i < electricCar.size(); i++)
						{
							dataBaseEcar += (to_string(i + 1) + ". " + electricCar[i].getManufacturer() + ' ' + electricCar[i].getModel() + '\n');
						}
						break;
					}
					else
					{
						system("cls");
						cout << "Нет электромабилей!\n";
						system("pause");
					}
					break;
				}
				if (choice2 == 3) // Гибрибные автомобили
				{
					if (!hybridCar.empty())
					{
						system("cls");
						choice3 = CheckERRORS("Введите номер автомобиля:\n" + dataBaseHcar, 1, HC_i);
						hybridCar.erase(hybridCar.begin() + (choice3 - 1));
						dataBaseHcar.clear();
						HC_i--;
						for (int i = 0; i < hybridCar.size(); i++)
						{
							dataBaseHcar += (to_string(i + 1) + ". " + hybridCar[i].getManufacturer() + ' ' + hybridCar[i].getModel() + '\n');
						}
						break;
					}
					else
					{
						system("cls");
						cout << "Нет гибридных автомобилей!\n";
						system("pause");
					}
				}
				if (choice2 == 4) break;
				break;
			}
			if (choice1 == 2) ////////////////////////// ЭЛЕКТРИЧКИ //////////////////////////
			{
				system("cls");
				choice2 = CheckERRORS("Виберите вид электрички: \n1. Обычная электричка\n2. Экспресс электричка \n3. Выход", 1, 3);
				if (choice2 == 1)
				{
					if (!simpleTrain.empty())
					{
						system("cls");
						choice3 = CheckERRORS("Введите номер электрички:\n" + dataBaseStrain, 1, ST_i);
						simpleTrain.erase(simpleTrain.begin() + (choice3 - 1));
						dataBaseStrain.clear();
						ST_i--;
						for (int i = 0; i < simpleTrain.size(); i++)
						{
							dataBaseStrain += (to_string(i + 1) + ". " + simpleTrain[i].getNameTrain() + ' ' + simpleTrain[i].getModel() + '\n');
						}
						break;
					}
					else
					{
						system("cls");
						cout << "Нет электричек!\n";
						system("pause");
					}
				}
				break;
				if (choice2 == 1)
				{
					if (!expressTrain.empty())
					{
						system("cls");
						choice3 = CheckERRORS("Введите номер электрички:\n" + dataBaseEtrain, 1, ET_i);
						expressTrain.erase(expressTrain.begin() + (choice3 - 1));
						dataBaseEtrain.clear();
						ET_i--;
						for (int i = 0; i < expressTrain.size(); i++)
						{
							dataBaseEtrain += (to_string(i + 1) + ". " + expressTrain[i].getNameTrain() + ' ' + expressTrain[i].getModel() + '\n');
						}
						break;
					}
					else
					{
						system("cls");
						cout << "Нет экспресс электричек!\n";
						system("pause");
					}
				}
				break;
			}
			if (choice1 == 3) break;
			system("cls");
			break;
		}
		case 5:
		{
			system("cls");
			string login;
			string password;
			login = CheckERRORS_string("Введите логин:", 49);
			password = CheckERRORS_string("Введите пароль:", 49);

			if (login == "Krikunov" && password == "nano8")
			{
				int choice;
			}
			else
			{
				system("cls");
				cout << "Неверный логин или пароль\n";
				system("pause");
			}
			break;
		}
		default:
			cout << "Данной команды не существует!\n";
			break;
		}
	}
	return 0;
}
// Проверка
int CheckERRORS(string messages, int firstNumberComands, int lastNumberComands)
{
	bool good = false;
	int n;
	while (!good)
	{
		try
		{
			cout << messages << "\n>> ";
			cin >> n;
			if (cin.fail())
				throw invalid_argument("Некоректный ввод символов!\n");
			if (n < firstNumberComands || n > lastNumberComands)
				throw invalid_argument("Команда не найдена!\n");
			good = true;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		catch (const invalid_argument& ERRORE)
		{
			system("cls");
			cout << ERRORE.what();
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			system("pause");
			system("cls");
		}
	}
	return n;
}
string CheckERRORS_string(string messages, int lastNumberComands)
{
	bool good = false;
	int firstNumberComands = 1;
	string n;
	while (!good)
	{
		try
		{
			cout << messages << "\n>> ";
			cin >> n;
			if (cin.fail())
				throw invalid_argument("Некоректный ввод символов!\n");
			if (n.size() < firstNumberComands)
				throw invalid_argument("Слишком мало символов!\n");
			if (n.size() > lastNumberComands)
				throw invalid_argument("Слишком много символов!\n");
			good = true;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		catch (const invalid_argument& ERRORE)
		{
			system("cls");
			cout << ERRORE.what();
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			system("pause");
			system("cls");
		}
	}
	return n;
}
double CheckERRORS_double(string messages, double firstNumberComands, double lastNumberComands)
{
	bool good = false;
	double n;
	string input;
	while (!good)
	{
		try
		{
			cout << messages << "\n>> ";
			cin >> input;
			for (char& c : input) {
				if (c == ',') c = '.';
			}
			istringstream stream(input);
			if (!(stream >> n))
				throw invalid_argument("Некоректный ввод символов!\n");
			if (!(n > firstNumberComands && n < lastNumberComands))
				throw invalid_argument("Выход за диапозон!\n");
			good = true;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		catch (const invalid_argument& ERRORE)
		{
			system("cls");
			cout << ERRORE.what();
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			system("pause");
			system("cls");
		}
	}
	return n;
}
int CheckERRORS_int(string messages, int firstNumberComands, int lastNumberComands)
{
	bool good = false;
	int n;
	while (!good)
	{
		try
		{
			cout << messages << "\n>> ";
			cin >> n;
			if (cin.fail())
				throw invalid_argument("Некоректный ввод символов!\n");
			if (n < firstNumberComands + 1 || n > lastNumberComands - 1)
				throw invalid_argument("Выход за допустимый диапозон значений!\n");
			good = true;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		catch (const invalid_argument& ERRORE)
		{
			system("cls");
			cout << ERRORE.what();
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			system("pause");
			system("cls");
		}
	}
	return n;
}


void ShowInfoTransport(Transport* name)
{
	if (HybridCar* Hcar = dynamic_cast<HybridCar*>(name))
	{
		system("cls");
		cout << "-------------------------------------------------\n";
		cout << "Производитель:\t\t  | " << Hcar->getManufacturer() << '\n';
		cout << "-------------------------------------------------\n";
		cout << "Модлеь:\t\t\t  | " << Hcar->getModel() << '\n';
		cout << "-------------------------------------------------\n";
		cout << "Тип топлива:\t\t  | " << Hcar->getTypeFuel() << '\n';
		cout << "-------------------------------------------------\n";
		cout << "Габариты:\t\t  | " << Hcar->getDimension() << '\n';
		cout << "-------------------------------------------------\n";
		cout << "Вес:\t\t\t  | " << Hcar->getWeight() << " кг\n";
		cout << "-------------------------------------------------\n";
		cout << "Год выпуска:\t\t  | " << Hcar->getYearOfRelease() << '\n';
		cout << "-------------------------------------------------\n";
		cout << "Цена:\t\t\t  | " << (to_string(Hcar->getPriceTransport())).substr(0, 9) << " руб.\n";
		cout << "-------------------------------------------------\n";
		cout << "Максимальная скорость:\t  | " << Hcar->getMaxSpeed() << " км/ч\n";
		cout << "-------------------------------------------------\n";
		cout << "Расход топлива:\t\t  | " << Hcar->SimpleCar::getFuelConsumption() << " л/100 км\n";
		cout << "-------------------------------------------------\n";
		cout << "Текущая уровень бензина:  | " << Hcar->SimpleCar::getCurrentFuelAmount() << " л\n";
		cout << "-------------------------------------------------\n";
		cout << "Максимальная ёмкость бака:| " << Hcar->SimpleCar::getMaxFuelCapacity() << " л\n";
		cout << "-------------------------------------------------\n";
		cout << "Расход батареи:\t\t  | " << Hcar->ElectricCar::getFuelConsumption() << " кВт/100 км\n";
		cout << "-------------------------------------------------\n";
		cout << "Текущая уровень батареи:  | " << Hcar->ElectricCar::getCurrentFuelAmount() << " кВт\n";
		cout << "-------------------------------------------------\n";
		cout << "Макс. ёмкость батареи:    | " << Hcar->ElectricCar::getMaxFuelCapacity() << " кВт\n";
		cout << "-------------------------------------------------\n";
	}
	else if (SimpleCar* Scar = dynamic_cast<SimpleCar*>(name))
	{
		system("cls");
		cout << "-------------------------------------------------\n";
		cout << "Производитель:\t\t  | " << Scar->getManufacturer() << '\n';
		cout << "-------------------------------------------------\n";
		cout << "Модлеь:\t\t\t  | " << Scar->getModel() << '\n';
		cout << "-------------------------------------------------\n";
		cout << "Тип топлива:\t\t  | " << Scar->getTypeFuel() << '\n';
		cout << "-------------------------------------------------\n";
		cout << "Габариты:\t\t  | " << Scar->getDimension() << '\n';
		cout << "-------------------------------------------------\n";
		cout << "Вес:\t\t\t  | " << Scar->getWeight() << " кг\n";
		cout << "-------------------------------------------------\n";
		cout << "Год выпуска:\t\t  | " << Scar->getYearOfRelease() << '\n';
		cout << "-------------------------------------------------\n";
		cout << "Цена:\t\t\t  | " << (to_string(Scar->getPriceTransport())).substr(0, 9) << " руб.\n";
		cout << "-------------------------------------------------\n";
		cout << "Максимальная скорость:\t  | " << Scar->getMaxSpeed() << " км/ч\n";
		cout << "-------------------------------------------------\n";
		cout << "Расход топлива:\t\t  | " << Scar->getFuelConsumption() << " л/100 км\n";
		cout << "-------------------------------------------------\n";
		cout << "Текущая уровень бензина:  | " << Scar->getCurrentFuelAmount() << " л\n";
		cout << "-------------------------------------------------\n";
		cout << "Макс. ёмкость бака:\t  | " << Scar->getMaxFuelCapacity() << " л\n";
		cout << "-------------------------------------------------\n";
	}
	else if (ElectricCar* Ecar = dynamic_cast<ElectricCar*>(name))
	{
		system("cls");
		cout << "-------------------------------------------------\n";
		cout << "Производитель:\t\t  | " << Ecar->getManufacturer() << '\n';
		cout << "-------------------------------------------------\n";
		cout << "Модлеь:\t\t\t  | " << Ecar->getModel() << '\n';
		cout << "-------------------------------------------------\n";
		cout << "Тип топлива:\t\t  | " << Ecar->getTypeFuel() << '\n';
		cout << "-------------------------------------------------\n";
		cout << "Габариты:\t\t  | " << Ecar->getDimension() << '\n';
		cout << "-------------------------------------------------\n";
		cout << "Вес:\t\t\t  | " << Ecar->getWeight() << " кг\n";
		cout << "-------------------------------------------------\n";
		cout << "Год выпуска:\t\t  | " << Ecar->getYearOfRelease() << '\n';
		cout << "-------------------------------------------------\n";
		cout << "Цена:\t\t\t  | " << (to_string(Ecar->getPriceTransport())).substr(0, 9) << " руб.\n";
		cout << "-------------------------------------------------\n";
		cout << "Максимальная скорость:\t  | " << Ecar->getMaxSpeed() << " км/ч\n";
		cout << "-------------------------------------------------\n";
		cout << "Расход топлива:\t\t  | " << Ecar->getFuelConsumption() << " кВт/100 км\n";
		cout << "-------------------------------------------------\n";
		cout << "Текущая уровень бензина:  | " << Ecar->getCurrentFuelAmount() << " кВт\n";
		cout << "-------------------------------------------------\n";
		cout << "Макс. ёмкость бака:\t  | " << Ecar->getMaxFuelCapacity() << " кВт\n";
		cout << "-------------------------------------------------\n";
	}
	else if (ExpressTrain* Etrain = dynamic_cast<ExpressTrain*>(name))
	{
		system("cls");
		cout << "-------------------------------------------------\n";
		cout << "Название:\t\t  | " << Etrain->getNameTrain() << '\n';
		cout << "-------------------------------------------------\n";
		cout << "Производитель:\t\t  | " << Etrain->getManufacturer() << '\n';
		cout << "-------------------------------------------------\n";
		cout << "Модлеь:\t\t\t  | " << Etrain->getModel() << '\n';
		cout << "-------------------------------------------------\n";
		cout << "Тип топлива:\t\t  | " << Etrain->getTypeFuel() << '\n';
		cout << "-------------------------------------------------\n";
		cout << "Вес:\t\t\t  | " << Etrain->getWeight() << " кг\n";
		cout << "-------------------------------------------------\n";
		cout << "Год выпуска:\t\t  | " << Etrain->getYearOfRelease() << '\n';
		cout << "-------------------------------------------------\n";
		cout << "Цена:\t\t\t  | " << (to_string(Etrain->getPriceTransport())).substr(0, 9) << " руб.\n";
		cout << "-------------------------------------------------\n";
		cout << "Максимальная скорость:\t  | " << Etrain->getMaxSpeed() << " км/ч\n";
		cout << "-------------------------------------------------\n";
		cout << "Название:\t\t  | " << Etrain->getNameTrain() << '\n';
		cout << "-------------------------------------------------\n";
		cout << "Кол-во вагонов:\t\t  | " << Etrain->getNumberWagons() << '\n';
		cout << "-------------------------------------------------\n";
		cout << "Кол-во пассажирских мест: | " << Etrain->getPassengerCapacity() * Etrain->getNumberWagons() << "\n";
		cout << "-------------------------------------------------\n";
		cout << "Кол-во неактивных станций:| " << Etrain->getCountSkip() << "\n";
		cout << "-------------------------------------------------\n";
	}
	else if (SimpleTrain* Strain = dynamic_cast<SimpleTrain*>(name))
	{
		system("cls");
		cout << "-------------------------------------------------\n";
		cout << "Название:\t\t  | " << Strain->getNameTrain() << '\n';
		cout << "-------------------------------------------------\n";
		cout << "Производитель:\t\t  | " << Strain->getManufacturer() << '\n';
		cout << "-------------------------------------------------\n";
		cout << "Модлеь:\t\t\t  | " << Strain->getModel() << '\n';
		cout << "-------------------------------------------------\n";
		cout << "Тип топлива:\t\t  | " << Strain->getTypeFuel() << '\n';
		cout << "-------------------------------------------------\n";
		cout << "Габариты:\t\t  | " << Strain->getDimension() << '\n';
		cout << "-------------------------------------------------\n";
		cout << "Год выпуска:\t\t  | " << Strain->getYearOfRelease() << '\n';
		cout << "-------------------------------------------------\n";
		cout << "Цена:\t\t\t  | " << (to_string(Strain->getPriceTransport())).substr(0, 9) << " руб.\n";
		cout << "-------------------------------------------------\n";
		cout << "Максимальная скорость:\t  | " << Strain->getMaxSpeed() << " км/ч\n";
		cout << "-------------------------------------------------\n";
		cout << "Кол-во вагонов:\t\t  | " << Strain->getNumberWagons() << '\n';
		cout << "-------------------------------------------------\n";
		cout << "Кол-во пассажирских мест: | " << Strain->getPassengerCapacity() * Strain->getNumberWagons() << "\n";
		cout << "-------------------------------------------------\n";
	}
	system("pause");
}
void ShowRefill(Transport* name)
{
	SYSTEMTIME time;
	GetLocalTime(&time);
	system("cls");
	if (HybridCar* Hcar = dynamic_cast<HybridCar*>(name))
	{
		system("cls");
		if (!((Hcar->SimpleCar::getMaxFuelCapacity() - Hcar->SimpleCar::getCurrentFuelAmount() == 0) && (Hcar->ElectricCar::getMaxFuelCapacity() - Hcar->ElectricCar::getCurrentFuelAmount() == 0)))
		{
			cout << "=============================================================================================\n";
			cout << "Автомобиль: " << Hcar->getManufacturer() << ' ' << Hcar->getModel() << '\n';
			cout << "=============================================================================================\n";
			cout << "Объём бака автомобиля: " << '\t' << Hcar->SimpleCar::getMaxFuelCapacity() << '\t' << '\t' << "| Объём батареи автомобиля: " << Hcar->ElectricCar::getMaxFuelCapacity() << '\n';
			cout << "Текущий объём бензина: " << '\t' << Hcar->SimpleCar::getCurrentFuelAmount() << '\t' << '\t' << "| Текущий уровень батареи: " << Hcar->ElectricCar::getCurrentFuelAmount() << '\n';
			cout << "---------------------------------------------------------------------------------------------\n";
			cout << "Можно дозаправить бак на " << Hcar->SimpleCar::getMaxFuelCapacity() - Hcar->SimpleCar::getCurrentFuelAmount() << " литров.";
			cout << '\t' << "| Можно дозарядить батарею на " << Hcar->ElectricCar::getMaxFuelCapacity() - Hcar->ElectricCar::getCurrentFuelAmount() << " кВт.\n";
			int choice3;
			int choice4;
			cout << "=============================================================================================\n";
			cout << "Заправка на бензине АИ-92 ......................................... " << Hcar->SimpleCar::PriceOfRefuelingOrCharging() << "  руб." << endl;
			Hcar->setIsFuel95(true);
			cout << "Заправка на бензине АИ-95 ......................................... " << Hcar->SimpleCar::PriceOfRefuelingOrCharging() << " руб." << endl;
			Hcar->setIsFuel95(false);
			cout << "Стоимость зарядки батареи ......................................... " << Hcar->ElectricCar::PriceOfRefuelingOrCharging() << " руб.\n";
			cout << "=============================================================================================\n";
			cout << '[' << Hcar->TimeForRefuelingOrCharging(1) << "] время зарядки батареи от стандартной станции Tesla.\tНадбавка к стоимости 250 руб.\n";
			cout << '[' << Hcar->TimeForRefuelingOrCharging(2) << "] время зарядки батареи от быстрой станции Tesla.\tНадбавка к стоимости 500 руб.\n";
			cout << "=============================================================================================\n";
			choice3 = CheckERRORS("Каким бензином хотите заправить автомобиль: \n1. АИ-92 \n2. АИ-95", 1, 2);
			choice4 = CheckERRORS("Каким типом зарядки вы хотите зарядить автомобиль:\n1. От стандартной станции Tesla\n2. От быстрой станции Tesla", 1, 2);
			if (choice3 == 1 && choice4 == 1)
			{
				system("cls");
				cout << "            Чек\n";
				cout << "Автомобиль \t" << Hcar->getManufacturer() << ' ' << Hcar->getModel() << '\n';
				cout << "Дата/Время  \t" << time.wDay << '.' << time.wMonth << '.' << time.wYear << "/" << time.wHour << ':' << time.wMinute << ':' << time.wSecond << "\n";
				cout << "Заправлен  \t" << Hcar->SimpleCar::getMaxFuelCapacity() - Hcar->SimpleCar::getCurrentFuelAmount() << " л х " << Hcar->SimpleCar::getPriceFuel_92() << " руб/л. \n";
				cout << "Тип бензина  \tАИ-92\n";
				cout << "Заряжен  \t" << Hcar->ElectricCar::getMaxFuelCapacity() - Hcar->ElectricCar::getCurrentFuelAmount() << " кВт х " << Hcar->ElectricCar::getPriceElectricity() << " руб/кВт. \n";
				cout << "Тип зарядки  \tСтандартная станция Tesla\n";
				cout << "Время зарядки  \t[" << Hcar->TimeForRefuelingOrCharging(1) << "]\n";
				cout << "Итог .......... " << Hcar->SimpleCar::PriceOfRefuelingOrCharging() + Hcar->ElectricCar::PriceOfRefuelingOrCharging() + 250 << " руб.\n";
				Hcar->SimpleCar::refuelingCar();
				Hcar->ElectricCar::refuelingCar();
				system("pause");
			}
			if (choice3 == 1 && choice4 == 2)
			{
				system("cls");
				cout << "            Чек\n";
				cout << "Автомобиль \t" << Hcar->getManufacturer() << ' ' << Hcar->getModel() << '\n';
				cout << "Дата/Время  \t" << time.wDay << '.' << time.wMonth << '.' << time.wYear << "/" << time.wHour << ':' << time.wMinute << ':' << time.wSecond << "\n";
				cout << "Заправлен  \t" << Hcar->SimpleCar::getMaxFuelCapacity() - Hcar->SimpleCar::getCurrentFuelAmount() << " л х " << Hcar->SimpleCar::getPriceFuel_92() << " руб/л. \n";
				cout << "Тип бензина  \tАИ-92\n";
				cout << "Заряжен  \t" << Hcar->ElectricCar::getMaxFuelCapacity() - Hcar->ElectricCar::getCurrentFuelAmount() << " кВт х " << Hcar->ElectricCar::getPriceElectricity() << " руб/кВт. \n";
				cout << "Тип зарядки  \tБыстрая станция Tesla\n";
				cout << "Время зарядки  \t[" << Hcar->TimeForRefuelingOrCharging(2) << "]\n";
				cout << "Итог .......... " << Hcar->SimpleCar::PriceOfRefuelingOrCharging() + Hcar->ElectricCar::PriceOfRefuelingOrCharging() + 250 << " руб.\n";
				Hcar->SimpleCar::refuelingCar();
				Hcar->ElectricCar::refuelingCar();
				system("pause");
			}
			if (choice3 == 2 && choice4 == 1)
			{
				system("cls");
				cout << "            Чек\n";
				cout << "Автомобиль \t" << Hcar->getManufacturer() << ' ' << Hcar->getModel() << '\n';
				cout << "Дата/Время  \t" << time.wDay << '.' << time.wMonth << '.' << time.wYear << "/" << time.wHour << ':' << time.wMinute << ':' << time.wSecond << "\n";
				cout << "Заправлен  \t" << Hcar->SimpleCar::getMaxFuelCapacity() - Hcar->SimpleCar::getCurrentFuelAmount() << " л х " << Hcar->SimpleCar::getPriceFuel_95() << " руб/л. \n";
				cout << "Тип бензина  \tАИ-95\n";
				cout << "Заряжен  \t" << Hcar->ElectricCar::getMaxFuelCapacity() - Hcar->ElectricCar::getCurrentFuelAmount() << " кВт х " << Hcar->ElectricCar::getPriceElectricity() << " руб/кВт. \n";
				cout << "Тип зарядки  \tСтандартная станция Tesla\n";
				Hcar->SimpleCar::setIsFuel95(true);
				cout << "Время зарядки  \t[" << Hcar->TimeForRefuelingOrCharging(1) << "]\n";
				cout << "Итог .......... " << Hcar->SimpleCar::PriceOfRefuelingOrCharging() + Hcar->ElectricCar::PriceOfRefuelingOrCharging() + 500 << " руб.\n";
				Hcar->SimpleCar::refuelingCar();
				Hcar->SimpleCar::setIsFuel95(false);
				Hcar->ElectricCar::refuelingCar();
				system("pause");
			}
			if (choice3 == 2 && choice4 == 2)
			{
				system("cls");
				cout << "            Чек\n";
				cout << "Автомобиль \t" << Hcar->getManufacturer() << ' ' << Hcar->getModel() << '\n';
				cout << "Дата/Время  \t" << time.wDay << '.' << time.wMonth << '.' << time.wYear << "/" << time.wHour << ':' << time.wMinute << ':' << time.wSecond << "\n";
				cout << "Заправлен  \t" << Hcar->SimpleCar::getMaxFuelCapacity() - Hcar->SimpleCar::getCurrentFuelAmount() << " л х " << Hcar->SimpleCar::getPriceFuel_95() << " руб/л. \n";
				cout << "Тип бензина  \tАИ-95\n";
				cout << "Заряжен  \t" << Hcar->ElectricCar::getMaxFuelCapacity() - Hcar->ElectricCar::getCurrentFuelAmount() << " кВт х " << Hcar->ElectricCar::getPriceElectricity() << " руб/кВт. \n";
				cout << "Тип зарядки  \tБыстрая станция Tesla\n";
				cout << "Время зарядки  \t[" << Hcar->TimeForRefuelingOrCharging(2) << "]\n";
				Hcar->SimpleCar::setIsFuel95(true);
				cout << "Итог .......... " << Hcar->SimpleCar::PriceOfRefuelingOrCharging() + Hcar->ElectricCar::PriceOfRefuelingOrCharging() + 500 << " руб.\n";
				Hcar->SimpleCar::refuelingCar();
				Hcar->SimpleCar::setIsFuel95(false);
				Hcar->ElectricCar::refuelingCar();
				system("pause");
			}
		}
		else
		{
			ShowInfo("Автомобиль " + Hcar->getManufacturer() + Hcar->getModel() + " заправлен и заряжен до полна!");
		}
	}
	else if (SimpleCar* Scar = dynamic_cast<SimpleCar*>(name))
	{
		if (!(Scar->getMaxFuelCapacity() - Scar->getCurrentFuelAmount() == 0))
		{
			cout << "==================================================\n";
			cout << "Автомобиль: " << Scar->getManufacturer() << ' ' << Scar->getModel() << '\n';
			cout << "==================================================\n";
			cout << "Объём бака автомобиля: " << '\t' << Scar->getMaxFuelCapacity() << '\n';
			cout << "Текущий объём бензина: " << '\t' << Scar->getCurrentFuelAmount() << '\n';
			cout << "--------------------------------------------------\n";
			cout << "Можно дозаправить бак на " << Scar->getMaxFuelCapacity() - Scar->getCurrentFuelAmount() << " литров. \n";
			int choice3;
			cout << "==================================================\n";
			cout << "Заправка на бензине АИ-92 обоёдется в " << Scar->PriceOfRefuelingOrCharging() << " руб." << endl;
			Scar->setIsFuel95(true);
			cout << "Заправка на бензине АИ-95 обоёдется в " << Scar->PriceOfRefuelingOrCharging() << " руб." << endl;
			Scar->setIsFuel95(false);
			cout << "==================================================\n";
			choice3 = CheckERRORS("Каким бензином хотите заправить автомобиля: \n1. АИ-92 \n2. АИ-95: ", 1, 2);
			if (choice3 == 1)
			{
				system("cls");
				cout << "            Чек\n";
				cout << "Автомобиль  \t" << Scar->getManufacturer() << ' ' << Scar->getModel() << '\n';
				cout << "Дата/Время  \t" << time.wDay << '.' << time.wMonth << '.' << time.wYear << "/" << time.wHour << ':' << time.wMinute << ':' << time.wSecond << "\n";
				cout << "Заправлено  \t" << Scar->getMaxFuelCapacity() - Scar->getCurrentFuelAmount() << " л x " << Scar->getPriceFuel_92() << " руб/л. \n";
				cout << "Тип бензина \tАИ-92\n";
				cout << "Итог .......... " << Scar->PriceOfRefuelingOrCharging() << " руб.\n";
				Scar->refuelingCar();
				system("pause");
			}
			if (choice3 == 2)
			{
				system("cls");
				cout << "            Чек\n";
				cout << "Автомобиль  \t" << Scar->getManufacturer() << ' ' << Scar->getModel() << '\n';
				cout << "Дата/Время  \t" << time.wDay << '.' << time.wMonth << '.' << time.wYear << "/" << time.wHour << ':' << time.wMinute << ':' << time.wSecond << "\n";
				cout << "Заправлено  \t" << Scar->getMaxFuelCapacity() - Scar->getCurrentFuelAmount() << " л x " << Scar->getPriceFuel_95() << " руб/л. \n";
				cout << "Тип бензина \tАИ-95\n";
				Scar->setIsFuel95(true);
				cout << "Итог .......... " << Scar->PriceOfRefuelingOrCharging() << " руб.\n";
				Scar->setIsFuel95(false);
				Scar->refuelingCar();
				system("pause");
			}
		}
		else    ShowInfo("Автомобиль " + Scar->getManufacturer() + Scar->getModel() + " заправлен!");
	}
	else if (ElectricCar* Ecar = dynamic_cast<ElectricCar*>(name))
	{
		system("cls");
		if (!(Ecar->getMaxFuelCapacity() - Ecar->getCurrentFuelAmount() == 0))
		{
			cout << "=============================================================================================\n";
			cout << "Автомобиль: " << Ecar->getManufacturer() << ' ' << Ecar->getModel() << '\n';
			cout << "=============================================================================================\n";
			cout << "Объём батареи автомобиля: " << Ecar->getMaxFuelCapacity() << '\n';
			cout << "Текущий уровень батареи:  " << Ecar->getCurrentFuelAmount() << '\n';
			cout << "---------------------------------------------------------------------------------------------\n";
			cout << "Можно дозарядить батарею на " << Ecar->getMaxFuelCapacity() - Ecar->getCurrentFuelAmount() << " кВт.\n";
			cout << "=============================================================================================\n";
			cout << "Стоимость зарядки: " << Ecar->PriceOfRefuelingOrCharging() << " руб.\n";
			int choice3;
			cout << "=============================================================================================\n";
			cout << '[' << Ecar->TimeForRefuelingOrCharging(0) << "] время зарядки батареи от розетки 220В. \t\tНет надбавки.\n";
			cout << '[' << Ecar->TimeForRefuelingOrCharging(1) << "] время зарядки батареи от стандартной станции Tesla. \tНадбавка к стоимости 250 руб.\n";
			cout << '[' << Ecar->TimeForRefuelingOrCharging(2) << "] время зарядки батареи от быстрой станции Tesla. \tНадбавка к стоимости 500 руб.\n";
			cout << "=============================================================================================\n";
			choice3 = CheckERRORS("Каким типом зарядки вы хотите зарядить автомобиль: \n1. От розетки 220В\n2. От стандартной станции Tesla\n3. От быстрой станции Tesla ", 1, 3);
			if (choice3 == 1)
			{
				system("cls");
				cout << "       Вы решили зарядится дома\n";
				cout << "Автомобиль \t" << Ecar->getManufacturer() << ' ' << Ecar->getModel() << "\n";
				cout << "Дата/Время  \t" << time.wDay << '.' << time.wMonth << '.' << time.wYear << "/" << time.wHour << ':' << time.wMinute << ':' << time.wSecond << "\n";
				cout << "Заряжен  \t" << Ecar->ElectricCar::getMaxFuelCapacity() - Ecar->ElectricCar::getCurrentFuelAmount() << " кВт х " << Ecar->ElectricCar::getPriceElectricity() << " руб/кВт. \n";
				cout << "Тип зарядки  \tОт розетки 220В\n";
				cout << "Время зарядки\t" << "[" << Ecar->TimeForRefuelingOrCharging(0) << "]\n";
				cout << "Итог .......... " << Ecar->PriceOfRefuelingOrCharging() << "руб.\n";
				Ecar->refuelingCar();
				system("pause");
			}
			if (choice3 == 2)
			{
				system("cls");
				cout << "            Чек\n";
				cout << "Автомобиль \t" << Ecar->getManufacturer() << ' ' << Ecar->getModel() << "  заряжен до 100%.\n";
				cout << "Дата/Время  \t" << time.wDay << '.' << time.wMonth << '.' << time.wYear << "/" << time.wHour << ':' << time.wMinute << ':' << time.wSecond << "\n";
				cout << "Заряжен  \t" << Ecar->ElectricCar::getMaxFuelCapacity() - Ecar->ElectricCar::getCurrentFuelAmount() << " кВт х " << Ecar->ElectricCar::getPriceElectricity() << " руб/кВт. \n";
				cout << "Тип зарядки  \tСтандартная станция Tesla\n";
				cout << "Время зарядки\t" << Ecar->TimeForRefuelingOrCharging(1) << '\n';
				cout << "Итог .......... " << Ecar->PriceOfRefuelingOrCharging() + 250 << "руб.\n";
				Ecar->refuelingCar();
				system("pause");
			}
			if (choice3 == 3)
			{
				system("cls");
				cout << "            Чек\n";
				cout << "Автомобиль \t" << Ecar->getManufacturer() << ' ' << Ecar->getModel() << "  заряжен до 100%.\n";
				cout << "Дата/Время  \t" << time.wDay << '.' << time.wMonth << '.' << time.wYear << "/" << time.wHour << ':' << time.wMinute << ':' << time.wSecond << "\n";
				cout << "Заряжен  \t" << Ecar->ElectricCar::getMaxFuelCapacity() - Ecar->ElectricCar::getCurrentFuelAmount() << " кВт х " << Ecar->ElectricCar::getPriceElectricity() << " руб/кВт. \n";
				cout << "Тип зарядки  \tБыстрой станции Tesla\n";
				cout << "Время зарядки\t" << Ecar->TimeForRefuelingOrCharging(2) << '\n';
				cout << "Итог .......... " << Ecar->PriceOfRefuelingOrCharging() + 500 << "руб.\n";
				Ecar->refuelingCar();
				system("pause");
			}
		}
		else	ShowInfo("Автомобиль " + Ecar->getManufacturer() + Ecar->getModel() + " заряжен на 100%!");
	}
}
void CreateTransport(Transport* name)
{
	if (SimpleCar* Scar = dynamic_cast<SimpleCar*>(name))
	{
		system("cls");
		string Sinfo;
		unsigned int UInfo;
		double Dinfo;
		cout << "Введите марку автомобиля\n";
		cin >> Sinfo;
		Scar->setManufacturer(Sinfo);

		cout << "Введите модлеь автомобиля\n";
		cin >> Sinfo;
		Scar->setModel(Sinfo);

		Scar->setTypeFuel("GasOlin");

		cout << "Введите габариты автомобиля\n";
		cin >> Sinfo;
		Scar->setDimension(Sinfo);

		cout << "Введите вес автомобиля\n";
		cin >> Dinfo;
		Scar->setWeight(Dinfo);

		cout << "Введите год выпуска автомобиля\n";
		cin >> UInfo;
		Scar->setYearOfRelease(UInfo);

		cout << "Введите цену автомобиля\n";
		cin >> Dinfo;
		Scar->setPriceTransport(Dinfo);
		name = Scar;
	}
}
void ShowInfo(string messages)
{
	system("cls");
	cout << messages << endl;
	system("pause");
}
int TESTCreateTransport(vector<Transport*>& Tarr)
{
	/////////////////////////////////////
	string StringINFO;
	int IntINFO;
	double DoubleINFO;
	/////////////////////////////////////
	if (HybridCar* HCar = dynamic_cast<HybridCar*>(Tarr[Tarr.size() - 1]))
	{
		system("cls");
		HybridCar newCar;
		cout << "Начало сознание гибридного автомобиля\n";
		cout << "=================================================================\n";
		StringINFO = CheckERRORS_string("Введите марку автомобиля (Макс. 50 символов)", 49);
		HCar->setManufacturer(StringINFO);
		cout << "=================================================================\n";
		StringINFO = CheckERRORS_string("Введите модель автомобиля (Макс. 50 символов)", 49);
		HCar->setModel(StringINFO);
		HCar->setTypeFuel("GasOlin & Electricity");
		cout << "=================================================================\n";
		StringINFO.clear();
		cout << "Введите габариты автомобиля [мм]\n";
		int l, w, h;
		l = CheckERRORS_int("Введите длину автомобиля [мм] (от 1000 до 12000)", 999, 12001);
		w = CheckERRORS_int("Ведите ширину автомобиля [мм] (от 500  до 2500)", 499, 2501);
		h = CheckERRORS_int("Введите высоту автомобиля [мм] (от 1000 до 4000)", 999, 4001);
		HCar->setDimension(to_string(l) + ' ' + to_string(w) + ' ' + to_string(h) + " мм");
		cout << "=================================================================\n";
		DoubleINFO = CheckERRORS_double("Введите вес автомобиля [кг] (от 700 до 2500)", 699, 2501);
		HCar->setWeight(DoubleINFO);
		cout << "=================================================================\n";
		IntINFO = CheckERRORS_int("Введите год выпуска автомобиля (от 1885 до 2024)", 1884, 2025);
		HCar->setYearOfRelease(IntINFO);
		cout << "=================================================================\n";
		DoubleINFO = CheckERRORS_double("Введите цену автомобиля [рубли] (от 0 до 2147483646)", -1, INT_MAX);
		HCar->setPriceTransport(DoubleINFO);
		cout << "=================================================================\n";
		DoubleINFO = CheckERRORS_double("Введите максимальную скорость автомобиля [км/ч] (от 10 до 508.72)", 9, 508.73);
		///////////////////////////////////////
		HCar->setMaxSpeed(DoubleINFO);
		HCar->SimpleCar::setCurrentFuelAmount(0);
		cout << "=================================================================\n";
		DoubleINFO = CheckERRORS_double("Введите максимальную ёмкость бензинового бака автомобиля [литр] (от 30 до 100)", 29, 101);
		HCar->SimpleCar::setMaxFuelCapacity(DoubleINFO);
		cout << "=================================================================\n";
		DoubleINFO = CheckERRORS_double("Введите расход бензина автомобиля [1 литр / 100 км] (от 4 до 100)", 3, 101);
		HCar->SimpleCar::setFuelConsumption(DoubleINFO);
		///////////////////////////////////////
		HCar->ElectricCar::setCurrentFuelAmount(0);
		cout << "=================================================================\n";
		DoubleINFO = CheckERRORS_double("Введите максимальную ёмкость батареи автомобиля [кВт] (от 30 до 100)", 29, 101);
		HCar->ElectricCar::setMaxFuelCapacity(DoubleINFO);
		cout << "=================================================================\n";
		DoubleINFO = CheckERRORS_double("Введите расход батареи автомобиля [1 кВт-ч/ 100 км] (от 5 до 100)", 4, 101);
		HCar->ElectricCar::setFuelConsumption(DoubleINFO);
		cout << "=================================================================\n";
		cout << "Коней создания гибридного автомобиля\n";
		system("pause");
		return 0;
	}
	if (SimpleCar* SCar = dynamic_cast<SimpleCar*>(Tarr[Tarr.size() - 1]))
	{
		system("cls");
		HybridCar newCar;
		cout << "Начало сознание автомобиля с ДВС\n";
		cout << "=================================================================\n";
		StringINFO = CheckERRORS_string("Введите марку автомобиля с ДВС (Макс. 50 символов)", 49);
		SCar->setManufacturer(StringINFO);
		cout << "=================================================================\n";
		StringINFO = CheckERRORS_string("Введите модель автомобиля с ДВС (Макс. 50 символов)", 49);
		SCar->setModel(StringINFO);
		SCar->setTypeFuel("GasOlin");
		cout << "=================================================================\n";
		StringINFO.clear();
		cout << "Введите габариты автомобиля [мм]\n";
		int l, w, h;
		l = CheckERRORS_int("Введите длину автомобиля с ДВС [мм] (от 1000 до 12000)", 999, 12001);
		w = CheckERRORS_int("Ведите ширину автомобиля с ДВС [мм] (от 500  до 2500)", 499, 2501);
		h = CheckERRORS_int("Введите высоту автомобиля с ДВС [мм] (от 1000 до 4000)", 999, 4001);
		SCar->setDimension(to_string(l) + ' ' + to_string(w) + ' ' + to_string(h) + " мм");
		cout << "=================================================================\n";
		DoubleINFO = CheckERRORS_double("Введите вес автомобиля с ДВС [кг] (от 700 до 2500)", 699, 2501);
		SCar->setWeight(DoubleINFO);
		cout << "=================================================================\n";
		IntINFO = CheckERRORS_int("Введите год выпуска автомобиля с ДВС (от 1885 до 2024)", 1884, 2025);
		SCar->setYearOfRelease(IntINFO);
		cout << "=================================================================\n";
		DoubleINFO = CheckERRORS_double("Введите цену автомобиля с ДВС [рубли] (от 0 до 2147483646)", -1, INT_MAX);
		SCar->setPriceTransport(DoubleINFO);
		cout << "=================================================================\n";
		DoubleINFO = CheckERRORS_double("Введите максимальную скорость автомобиля с ДВС [км/ч] (от 10 до 508.72)", 9, 508.73);
		///////////////////////////////////////
		SCar->setMaxSpeed(DoubleINFO);
		SCar->setCurrentFuelAmount(0);
		cout << "=================================================================\n";
		DoubleINFO = CheckERRORS_double("Введите максимальную ёмкость бензинового бака автомобиля с ДВС [литр] (от 30 до 100)", 29, 101);
		SCar->setMaxFuelCapacity(DoubleINFO);
		cout << "=================================================================\n";
		DoubleINFO = CheckERRORS_double("Введите расход бензина автомобиля с ДВС [1 литр / 100 км] (от 4 до 100)", 3, 101);
		SCar->setFuelConsumption(DoubleINFO);
		cout << "Коней создания гибридного автомобиля с ДВС\n";
		system("pause");
		return 0;
	}
	if (ElectricCar* ECar = dynamic_cast<ElectricCar*>(Tarr[Tarr.size() - 1]))
	{
		system("cls");
		HybridCar newCar;
		cout << "Начало сознание электромобиля\n";
		cout << "=================================================================\n";
		StringINFO = CheckERRORS_string("Введите марку электромобиля (Макс. 50 символов)", 49);
		ECar->setManufacturer(StringINFO);
		cout << "=================================================================\n";
		StringINFO = CheckERRORS_string("Введите модель электромобиля (Макс. 50 символов)", 49);
		ECar->setModel(StringINFO);
		ECar->setTypeFuel("GasOlin & Electricity");
		cout << "=================================================================\n";
		StringINFO.clear();
		cout << "Введите габариты электромобиля [мм]\n";
		int l, w, h;
		l = CheckERRORS_int("Введите длину электромобиля [мм] (от 1000 до 12000)", 999, 12001);
		w = CheckERRORS_int("Ведите ширину электромобиля [мм] (от 500  до 2500)", 499, 2501);
		h = CheckERRORS_int("Введите высоту электромобиля [мм] (от 1000 до 4000)", 999, 4001);
		ECar->setDimension(to_string(l) + ' ' + to_string(w) + ' ' + to_string(h) + " мм");
		cout << "=================================================================\n";
		DoubleINFO = CheckERRORS_double("Введите вес электромобиля [кг] (от 700 до 2500)", 699, 2501);
		ECar->setWeight(DoubleINFO);
		cout << "=================================================================\n";
		IntINFO = CheckERRORS_int("Введите год выпуска электромобиля (от 1885 до 2024)", 1884, 2025);
		ECar->setYearOfRelease(IntINFO);
		cout << "=================================================================\n";
		DoubleINFO = CheckERRORS_double("Введите цену электромобиля [рубли] (от 0 до 2147483646)", -1, INT_MAX);
		ECar->setPriceTransport(DoubleINFO);
		cout << "=================================================================\n";
		DoubleINFO = CheckERRORS_double("Введите максимальную скорость электромобиля [км/ч] (от 10 до 508.72)", 9, 508.73);
		///////////////////////////////////////
		ECar->setCurrentFuelAmount(0);
		cout << "=================================================================\n";
		DoubleINFO = CheckERRORS_double("Введите максимальную ёмкость батареи электромобиля [кВт] (от 30 до 100)", 29, 101);
		ECar->setMaxFuelCapacity(DoubleINFO);
		cout << "=================================================================\n";
		DoubleINFO = CheckERRORS_double("Введите расход батареи электромобиля [1 кВт-ч/ 100 км] (от 5 до 100)", 4, 101);
		ECar->setFuelConsumption(DoubleINFO);
		cout << "=================================================================\n";
		cout << "Коней создания электромобиля\n";
		system("pause");
		return 0;
	}
	if (SimpleTrain* STrain = dynamic_cast<SimpleTrain*>(Tarr[Tarr.size() - 1]))
	{
		system("cls");
		HybridCar newCar;
		cout << "Начало сознание электрички\n";
		cout << "=================================================================\n";
		StringINFO = CheckERRORS_string("Введите название электрички (Макс. 100 символов)", 99);
		STrain->setNameTrain(StringINFO);
		cout << "=================================================================\n";
		StringINFO = CheckERRORS_string("Введите производителя электрички (Макс. 100 символов)", 99);
		STrain->setManufacturer(StringINFO);
		cout << "=================================================================\n";
		StringINFO = CheckERRORS_string("Введите модель электрички (Макс. 100 символов)", 99);
		STrain->setModel(StringINFO);
		STrain->setTypeFuel("GasOlin & Electricity");
		cout << "=================================================================\n";
		StringINFO.clear();
		cout << "Введите габариты вагона электрички [мм]\n";
		int l, w, h;
		l = CheckERRORS_int("Введите длину вагона электрички [мм] (от 16200 до 24000)", 16199, 24001);
		w = CheckERRORS_int("Ведите ширину вагона электрички [мм] (от 3200  до 3400)", 3199, 3401);
		h = CheckERRORS_int("Введите высоту вагона электрички [мм] (от 4500 до 5200)", 4499, 5201);
		STrain->setDimension(to_string(l) + ' ' + to_string(w) + ' ' + to_string(h) + " мм");
		cout << "=================================================================\n";
		DoubleINFO = CheckERRORS_double("Введите вес вагона электрички [кг] (от 25000 до 50000)", 24999, 50001);
		STrain->setWeight(DoubleINFO);
		cout << "=================================================================\n";
		IntINFO = CheckERRORS_int("Введите год выпуска электрички (от 1929 до 2024)", 1928, 2025);
		STrain->setYearOfRelease(IntINFO);
		cout << "=================================================================\n";
		DoubleINFO = CheckERRORS_double("Введите цену вагона электрички [рубли] (от 0 до 2147483646)", -1, INT_MAX);
		STrain->setPriceTransport(DoubleINFO);
		cout << "=================================================================\n";
		DoubleINFO = CheckERRORS_double("Введите максимальную скорость электрички [км/ч] (от 20 до 250)", 19, 251);
		///////////////////////////////////////
		cout << "=================================================================\n";
		IntINFO = CheckERRORS_int("Введите количество вагонов в электричке [шт] (от 4 до 16)", 3, 17);
		STrain->setNumberWagons(IntINFO);
		cout << "=================================================================\n";
		IntINFO = CheckERRORS_int("Введите вместимость одного вагона электрички [шт] (от 30 до 250)", 29, 251);
		STrain->setPassengerCapacity(IntINFO);
		cout << "=================================================================\n";
		cout << "Коней создания электрички\n";
		system("pause");
		return 0;
	}

}

bool CarIsReady(Transport* name)
{
	if (HybridCar* Hcar = dynamic_cast<HybridCar*>(name))
	{
		try
		{
			if (Hcar->SimpleCar::getCurrentFuelAmount() < 3.5)
				throw invalid_argument("В автомобиле критически мало бензина!\nНеобходимо заправится!\n");
			if (Hcar->SimpleCar::getCurrentFuelAmount() <= 4 && Hcar->SimpleCar::getCurrentFuelAmount() >= 3.5)
				throw invalid_argument("В автомобиле мало бензина!\nНеобходимо заправится!\n");
			if (!Hcar->SimpleCar::getIsStarted())
				throw invalid_argument("Машина не заведена!\n");
			return true;
		}
		catch (const invalid_argument& ERRORE)
		{
			system("cls");
			cout << ERRORE.what();
			system("pause");
			system("cls");
			return 0;
		}
	}
	if (SimpleCar* Scar = dynamic_cast<SimpleCar*>(name))
	{
		try
		{
			if (Scar->getCurrentFuelAmount() < 3.5)
				throw invalid_argument("В автомобиле критически мало бензина!\nНеобходимо заправится!\n");
			if (Scar->getCurrentFuelAmount() <= 4 && Scar->getCurrentFuelAmount() >= 3.5)
				throw invalid_argument("В автомобиле мало бензина!\nНеобходимо заправится!\n");
			if (!Scar->getIsStarted())
				throw invalid_argument("Машина не заведена!\n");
			return true;
		}
		catch (const invalid_argument& ERRORE)
		{
			system("cls");
			cout << ERRORE.what();
			system("pause");
			system("cls");
			return 0;
		}
	}
	if (ElectricCar* Ecar = dynamic_cast<ElectricCar*>(name))
	{
		try
		{
			if (Ecar->getCurrentFuelAmount() < ((Ecar->getMaxFuelCapacity() * 15) / 100))
				throw invalid_argument("В автомобиле критически низкий уровень батареи!\nНеобходимо зарядится!\n");
			if (((Ecar->getCurrentFuelAmount() <= ((Ecar->getMaxFuelCapacity() * 25) / 100)) && (Ecar->getCurrentFuelAmount() >= ((Ecar->getMaxFuelCapacity() * 15) / 100))))
				throw invalid_argument("В автомобиле мало бензина!\nНеобходимо зарядится!\n");
			if (!Ecar->getIsStarted())
				throw invalid_argument("Машина не заведена!\n");
			return true;
		}
		catch (const invalid_argument& ERRORE)
		{
			system("cls");
			cout << ERRORE.what();
			system("pause");
			system("cls");
			return 0;
		}
	}
}