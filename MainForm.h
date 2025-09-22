#pragma once
#include "Ball.h" 
#include "Rectangle.h"
#include "Triangle.h"
#include "Star.h"
#include <stdlib.h> 
#include <cmath>

namespace PopBallv4 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	private:
		Ball* ballObj;
		MyRectangle* rectObj;
		Triangle* triangleObj;
		Star* starObj;
		int x1, y1, x2, y2;
		float nt = 0;
		float speedUp = 1.1f;
		float speedDown = 0.9f;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::RadioButton^ triangleBtn;

	private: System::Windows::Forms::RadioButton^ rectangleBtn;
	private: System::Windows::Forms::RadioButton^ ballBtn;
	private: System::Windows::Forms::RadioButton^ starBtn;
	private: System::Windows::Forms::CheckBox^ extensions;


	public:
		MainForm(void)
		{
			InitializeComponent();
			MouseWheel += gcnew MouseEventHandler(this, &MainForm::Form_MouseWheel);
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	public: System::Windows::Forms::PictureBox^ frame;
	private: System::Windows::Forms::Timer^ moveTimer;
	public:
	private: System::Windows::Forms::Timer^ drawTimer;
	private: System::ComponentModel::IContainer^ components;
	protected:

	private:

		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->frame = (gcnew System::Windows::Forms::PictureBox());
			this->moveTimer = (gcnew System::Windows::Forms::Timer(this->components));
			this->drawTimer = (gcnew System::Windows::Forms::Timer(this->components));
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->starBtn = (gcnew System::Windows::Forms::RadioButton());
			this->triangleBtn = (gcnew System::Windows::Forms::RadioButton());
			this->rectangleBtn = (gcnew System::Windows::Forms::RadioButton());
			this->ballBtn = (gcnew System::Windows::Forms::RadioButton());
			this->extensions = (gcnew System::Windows::Forms::CheckBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->frame))->BeginInit();
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// frame
			// 
			this->frame->Location = System::Drawing::Point(13, 13);
			this->frame->Name = L"frame";
			this->frame->Size = System::Drawing::Size(691, 532);
			this->frame->TabIndex = 0;
			this->frame->TabStop = false;
			this->frame->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MainForm::frame_Paint);
			this->frame->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::frame_MouseDown);
			this->frame->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::frame_MouseUp);
			// 
			// moveTimer
			// 
			this->moveTimer->Enabled = true;
			this->moveTimer->Interval = 10;
			this->moveTimer->Tick += gcnew System::EventHandler(this, &MainForm::moveTimer_Tick);
			// 
			// drawTimer
			// 
			this->drawTimer->Enabled = true;
			this->drawTimer->Interval = 10;
			this->drawTimer->Tick += gcnew System::EventHandler(this, &MainForm::drawTimer_Tick);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->starBtn);
			this->groupBox1->Controls->Add(this->triangleBtn);
			this->groupBox1->Controls->Add(this->rectangleBtn);
			this->groupBox1->Controls->Add(this->ballBtn);
			this->groupBox1->Location = System::Drawing::Point(719, 32);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(135, 222);
			this->groupBox1->TabIndex = 1;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Shape";
			// 
			// starBtn
			// 
			this->starBtn->AutoSize = true;
			this->starBtn->Location = System::Drawing::Point(26, 104);
			this->starBtn->Name = L"starBtn";
			this->starBtn->Size = System::Drawing::Size(42, 17);
			this->starBtn->TabIndex = 3;
			this->starBtn->TabStop = true;
			this->starBtn->Text = L"star";
			this->starBtn->UseVisualStyleBackColor = true;
			// 
			// triangleBtn
			// 
			this->triangleBtn->AutoSize = true;
			this->triangleBtn->Location = System::Drawing::Point(26, 80);
			this->triangleBtn->Name = L"triangleBtn";
			this->triangleBtn->Size = System::Drawing::Size(59, 17);
			this->triangleBtn->TabIndex = 2;
			this->triangleBtn->TabStop = true;
			this->triangleBtn->Text = L"triangle";
			this->triangleBtn->UseVisualStyleBackColor = true;
			// 
			// rectangleBtn
			// 
			this->rectangleBtn->AutoSize = true;
			this->rectangleBtn->Location = System::Drawing::Point(26, 56);
			this->rectangleBtn->Name = L"rectangleBtn";
			this->rectangleBtn->Size = System::Drawing::Size(69, 17);
			this->rectangleBtn->TabIndex = 1;
			this->rectangleBtn->TabStop = true;
			this->rectangleBtn->Text = L"rectangle";
			this->rectangleBtn->UseVisualStyleBackColor = true;
			// 
			// ballBtn
			// 
			this->ballBtn->AutoSize = true;
			this->ballBtn->Location = System::Drawing::Point(26, 32);
			this->ballBtn->Name = L"ballBtn";
			this->ballBtn->Size = System::Drawing::Size(41, 17);
			this->ballBtn->TabIndex = 0;
			this->ballBtn->TabStop = true;
			this->ballBtn->Text = L"ball";
			this->ballBtn->UseVisualStyleBackColor = true;
			// 
			// extensions
			// 
			this->extensions->AutoSize = true;
			this->extensions->Location = System::Drawing::Point(745, 328);
			this->extensions->Name = L"extensions";
			this->extensions->Size = System::Drawing::Size(75, 17);
			this->extensions->TabIndex = 2;
			this->extensions->Text = L"Extentions";
			this->extensions->UseVisualStyleBackColor = true;
			this->extensions->Click += gcnew System::EventHandler(this, &MainForm::extensions_Click);
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(882, 557);
			this->Controls->Add(this->extensions);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->frame);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Fixed3D;
			this->KeyPreview = true;
			this->Name = L"MainForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Pop Balls V4: Mix";
			this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MainForm::MainForm_KeyDown);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &MainForm::MainForm_KeyUp);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->frame))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void frame_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		Graphics^ grp = e->Graphics;
		manager->drawFrame(grp);
	}

	private: System::Void frame_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		if (e->Button == System::Windows::Forms::MouseButtons::Left) {
			PopObject* popBallObj = manager->search(e->X, e->Y);
			if (popBallObj == nullptr) {
				x1 = e->X;
				y1 = e->Y;
			}
			nt = 0;
		}
	}

	private: System::Void frame_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		if (e->Button == System::Windows::Forms::MouseButtons::Left) {
			PopObject* popBallObj = manager->search(e->X, e->Y);
			if (popBallObj == nullptr) {
				x2 = e->X;
				y2 = e->Y;
				if (ballBtn->Checked) {
					ballObj = new Ball(frame->Width, frame->Height, e->X, e->Y);
					if (x2 - x1 != 0 && y2 - y1 != 0) {
						if (nt == 0) {
							nt = 1;
						}
						float dX = (x2 - x1) / nt;
						float dY = (y2 - y1) / nt;
						ballObj->setSpeed(dX, dY);
					}
					manager->add(ballObj);
				}
				if (rectangleBtn->Checked) {
					rectObj = new MyRectangle(frame->Width, frame->Height, e->X, e->Y);
					if (x2 - x1 != 0 && y2 - y1 != 0) {
						if (nt == 0) {
							nt = 1;
						}
						float dX = (x2 - x1) / nt;
						float dY = (y2 - y1) / nt;
						rectObj->setSpeed(dX, dY);
					}
					manager->add(rectObj);
				}
				if (triangleBtn->Checked) {
					triangleObj = new Triangle(frame->Width, frame->Height, e->X, e->Y, 0.05f);
					if (x2 - x1 != 0 && y2 - y1 != 0) {
						if (nt == 0) {
							nt = 1;
						}
						float dX = (x2 - x1) / nt;
						float dY = (y2 - y1) / nt;
						triangleObj->setSpeed(dX, dY);
					}
					manager->add(triangleObj);

				}
				if (starBtn->Checked) {
					starObj = new Star(frame->Width, frame->Height, e->X, e->Y);
					if (x2 - x1 != 0 && y2 - y1 != 0) {
						if (nt == 0) {
							nt = 1;
						}
						float dX = (x2 - x1) / nt;
						float dY = (y2 - y1) / nt;
						starObj->setSpeed(dX, dY);
					}
					manager->add(starObj);
				}
			}
			else {
				manager->remove(popBallObj);
			}
		}
	}

	private: void Form_MouseWheel(Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
	{
		if (e->Delta < 0) {
			manager->setSpeedAll(speedDown);
		}
		else {
			manager->setSpeedAll(speedUp);
		}
	}

	private: System::Void moveTimer_Tick(System::Object^ sender, System::EventArgs^ e) {
		nt++;
		manager->move();
	}
	private: System::Void drawTimer_Tick(System::Object^ sender, System::EventArgs^ e) {
		frame->Invalidate();
	}

	private: System::Void MainForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		if (e->KeyCode == Keys::ControlKey) { moveTimer->Enabled = false; }
	}
	private: System::Void MainForm_KeyUp(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		if (e->KeyCode == Keys::ControlKey) { moveTimer->Enabled = true; }
	}
	private: System::Void MainForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void extensions_Click(System::Object^ sender, System::EventArgs^ e) {
		if (extensions->Checked) {
			manager->setExtention(true);
		}
		else {
			manager->setExtention(false);
		}
	}
	};
}
