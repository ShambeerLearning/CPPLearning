#pragma once

namespace Sasalka20 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	private:
		int hour = 0;
		int min = 0;
		int sec = 0;
		String^ Hour;
		String^ Min;
		DateTime currentTime;

		array<String^>^ randText;
	public:
	private: System::Windows::Forms::Button^ suckButton;
	private: System::Windows::Forms::Label^ showLabel;
	private: System::Windows::Forms::Label^ TimeMin;
	private: System::Windows::Forms::Label^ TimeSec;
	private: System::Windows::Forms::Timer^ noteTimer;



	public:

	public:

	public:
		String^ Sec;

		MyForm(void)
		{
			InitializeComponent();
			randText = gcnew array<String^> {
				"Я ОТСОСАЛ ХУЙ!!!",
					"О ДА! Я ХУЕГЛОТ!",
					"ОН ТАКОЙ ВКУСНЫЙ!",
					"ПРЯМО КАК У ТВОЕГО ОТЦА",
					"ВКУСНЫЙ МАЙОНЕЗ",
					"У МОЕЙ СОБАКИ БОЛЬШЕ",
					"ТЫ НЕ ТЫ, КОГДА ГОЛОДЕН",
					"ФУ БЛЯ, ВОЛОС",
					"АМ НЯМ НЯМ, КАКАЯ ВКУСНОТИЩА",
					"КТО ХУЙ СУЁТ МНЕ В ГОРЛО?",
					"СКОЛЬКО ХУЙ СМ",
					"МОЖЕТ В ЖОПУ?",
					"У МЕНЯ ГОРЛО ПЕРЕСОХЛО"
			};
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button_exit;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ TimeHour;

	private: System::Windows::Forms::Timer^ Timer;
	private: System::ComponentModel::IContainer^ components;


	protected:

	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->button_exit = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->TimeHour = (gcnew System::Windows::Forms::Label());
			this->Timer = (gcnew System::Windows::Forms::Timer(this->components));
			this->suckButton = (gcnew System::Windows::Forms::Button());
			this->showLabel = (gcnew System::Windows::Forms::Label());
			this->TimeMin = (gcnew System::Windows::Forms::Label());
			this->TimeSec = (gcnew System::Windows::Forms::Label());
			this->noteTimer = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// button_exit
			// 
			this->button_exit->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(115)),
				static_cast<System::Int32>(static_cast<System::Byte>(115)));
			this->button_exit->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button_exit->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button_exit->ForeColor = System::Drawing::Color::White;
			this->button_exit->Location = System::Drawing::Point(245, 12);
			this->button_exit->Name = L"button_exit";
			this->button_exit->Size = System::Drawing::Size(27, 19);
			this->button_exit->TabIndex = 0;
			this->button_exit->Text = L"X";
			this->button_exit->UseVisualStyleBackColor = false;
			this->button_exit->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(57)), static_cast<System::Int32>(static_cast<System::Byte>(57)),
				static_cast<System::Int32>(static_cast<System::Byte>(57)));
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 21.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->label1->Location = System::Drawing::Point(19, 43);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(231, 33);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Я не сосал хуй";
			// 
			// TimeHour
			// 
			this->TimeHour->AutoSize = true;
			this->TimeHour->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(57)), static_cast<System::Int32>(static_cast<System::Byte>(57)),
				static_cast<System::Int32>(static_cast<System::Byte>(57)));
			this->TimeHour->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 21.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->TimeHour->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->TimeHour->Location = System::Drawing::Point(19, 85);
			this->TimeHour->Name = L"TimeHour";
			this->TimeHour->Size = System::Drawing::Size(123, 33);
			this->TimeHour->TabIndex = 2;
			this->TimeHour->Text = L"0 часов";
			this->TimeHour->Click += gcnew System::EventHandler(this, &MyForm::TimeHour_Click);
			// 
			// Timer
			// 
			this->Timer->Enabled = true;
			this->Timer->Interval = 1000;
			this->Timer->Tick += gcnew System::EventHandler(this, &MyForm::Timer_Tick);
			// 
			// suckButton
			// 
			this->suckButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->suckButton->Location = System::Drawing::Point(23, 372);
			this->suckButton->Name = L"suckButton";
			this->suckButton->Size = System::Drawing::Size(237, 41);
			this->suckButton->TabIndex = 3;
			this->suckButton->Text = L"Отсосать хуй";
			this->suckButton->UseVisualStyleBackColor = true;
			this->suckButton->Click += gcnew System::EventHandler(this, &MyForm::suckButton_Click);
			// 
			// showLabel
			// 
			this->showLabel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(57)), static_cast<System::Int32>(static_cast<System::Byte>(57)),
				static_cast<System::Int32>(static_cast<System::Byte>(57)));
			this->showLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->showLabel->ForeColor = System::Drawing::Color::White;
			this->showLabel->Location = System::Drawing::Point(20, 199);
			this->showLabel->Name = L"showLabel";
			this->showLabel->Size = System::Drawing::Size(201, 80);
			this->showLabel->TabIndex = 4;
			this->showLabel->Text = L"Вы отсосали хуй!";
			this->showLabel->Visible = false;
			this->showLabel->Click += gcnew System::EventHandler(this, &MyForm::showLabel_Click);
			// 
			// TimeMin
			// 
			this->TimeMin->AutoSize = true;
			this->TimeMin->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(57)), static_cast<System::Int32>(static_cast<System::Byte>(57)),
				static_cast<System::Int32>(static_cast<System::Byte>(57)));
			this->TimeMin->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 21.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->TimeMin->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->TimeMin->Location = System::Drawing::Point(19, 118);
			this->TimeMin->Name = L"TimeMin";
			this->TimeMin->Size = System::Drawing::Size(127, 33);
			this->TimeMin->TabIndex = 5;
			this->TimeMin->Text = L"0 минут";
			this->TimeMin->Click += gcnew System::EventHandler(this, &MyForm::label2_Click);
			// 
			// TimeSec
			// 
			this->TimeSec->AutoSize = true;
			this->TimeSec->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(57)), static_cast<System::Int32>(static_cast<System::Byte>(57)),
				static_cast<System::Int32>(static_cast<System::Byte>(57)));
			this->TimeSec->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 21.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->TimeSec->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->TimeSec->Location = System::Drawing::Point(19, 151);
			this->TimeSec->Name = L"TimeSec";
			this->TimeSec->Size = System::Drawing::Size(141, 33);
			this->TimeSec->TabIndex = 6;
			this->TimeSec->Text = L"0 секунд";
			// 
			// noteTimer
			// 
			this->noteTimer->Enabled = true;
			this->noteTimer->Interval = 1000;
			this->noteTimer->Tick += gcnew System::EventHandler(this, &MyForm::noteTimer_Tick);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(57)), static_cast<System::Int32>(static_cast<System::Byte>(57)),
				static_cast<System::Int32>(static_cast<System::Byte>(57)));
			this->ClientSize = System::Drawing::Size(284, 461);
			this->Controls->Add(this->TimeSec);
			this->Controls->Add(this->TimeMin);
			this->Controls->Add(this->showLabel);
			this->Controls->Add(this->suckButton);
			this->Controls->Add(this->TimeHour);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button_exit);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"MyForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e)
	{
		DateTime dtTmp = DateTime::Now;
		TimeHour->Text = dtTmp.TimeOfDay.ToString();
	}
	private: System::Void Timer_Tick(System::Object^ sender, System::EventArgs^ e) {

		sec++;

		if (sec >= 60) {
			sec = 0;
			min++;
		}
		if (min >= 60) {
			min = 0;
			hour++;
		}
		if (hour >= 24) {
			hour = 0;
		}

		Sec = Convert::ToString(sec);
		Min = Convert::ToString(min);
		Hour = Convert::ToString(hour);

		TimeHour->Text = Hour + " часов";
		TimeMin->Text = Min + " минут";
		TimeSec->Text = Sec + " секунд";

	}
	private: System::Void suckButton_Click(System::Object^ sender, System::EventArgs^ e) {
		sec = 0;
		min = 0;
		hour = 0;

		currentTime = DateTime::Now;
		Random^ ran = gcnew Random();
		int RandKey = ran->Next(0, randText->Length);
		showLabel->Text = randText[RandKey];
		showLabel->Visible = true;
	}

	private: System::Void noteTimer_Tick(System::Object^ sender, System::EventArgs^ e) {
		if (currentTime.Second + 1 <= DateTime::Now.Second)
			showLabel->Visible = false;
	}
	private: System::Void showLabel_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void TimeHour_Click(System::Object^ sender, System::EventArgs^ e) {
	}
};
}