#pragma once

#include <msclr\marshal_cppstd.h>
#include <sstream>
#include "Header.h"

namespace ConsoleApplication1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	using namespace msclr::interop;

	/// <summary>
	/// Description résumée de form_main
	/// </summary>
	public ref class form_main : public System::Windows::Forms::Form
	{
	public:
		form_main(void)
		{
			InitializeComponent();
			//
			//TODO: ajoutez ici le code du constructeur
			//
		}

	protected:
		/// <summary>
		/// Nettoyage des ressources utilisées.
		/// </summary>
		~form_main()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	protected:
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::TextBox^  textBox2;



	private: System::Windows::Forms::TextBox^  textBox4;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::RichTextBox^  richTextBox2;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^  chart1;

	private: System::Windows::Forms::DataVisualization::Charting::Chart^  chart2;




	private:
		/// <summary>
		/// Variable nécessaire au concepteur.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Méthode requise pour la prise en charge du concepteur - ne modifiez pas
		/// le contenu de cette méthode avec l'éditeur de code.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataVisualization::Charting::ChartArea^  chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^  legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^  series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^  series2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^  series3 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Title^  title1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Title());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^  chartArea2 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^  legend2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^  series4 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^  series5 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^  series6 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Title^  title2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Title());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->richTextBox2 = (gcnew System::Windows::Forms::RichTextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->chart1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->chart2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart2))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(462, 15);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(111, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Durée de la simulation";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(462, 55);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(91, 13);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Durée interarrivée";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(579, 12);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 20);
			this->textBox1->TabIndex = 2;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(579, 52);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(100, 20);
			this->textBox2->TabIndex = 3;
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(579, 92);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(100, 20);
			this->textBox4->TabIndex = 10;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(462, 95);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(100, 13);
			this->label4->TabIndex = 9;
			this->label4->Text = L"Durée de traitement";
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(722, 12);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(104, 56);
			this->button3->TabIndex = 11;
			this->button3->Text = L"LANCER SIMULATION";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &form_main::button3_Click);
			// 
			// richTextBox2
			// 
			this->richTextBox2->Location = System::Drawing::Point(832, 12);
			this->richTextBox2->Name = L"richTextBox2";
			this->richTextBox2->ReadOnly = true;
			this->richTextBox2->ScrollBars = System::Windows::Forms::RichTextBoxScrollBars::Vertical;
			this->richTextBox2->Size = System::Drawing::Size(364, 279);
			this->richTextBox2->TabIndex = 12;
			this->richTextBox2->Text = L"";
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(1088, 630);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(108, 59);
			this->button2->TabIndex = 13;
			this->button2->Text = L"QUITTER";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &form_main::button2_Click_1);
			// 
			// chart1
			// 
			chartArea1->AxisX->ArrowStyle = System::Windows::Forms::DataVisualization::Charting::AxisArrowStyle::Triangle;
			chartArea1->AxisX->LineDashStyle = System::Windows::Forms::DataVisualization::Charting::ChartDashStyle::Dot;
			chartArea1->AxisX->MajorGrid->Enabled = false;
			chartArea1->AxisX->Minimum = 0;
			chartArea1->AxisX->Title = L"Temps";
			chartArea1->AxisY->ArrowStyle = System::Windows::Forms::DataVisualization::Charting::AxisArrowStyle::Triangle;
			chartArea1->AxisY->MajorGrid->Enabled = false;
			chartArea1->AxisY->Minimum = 0;
			chartArea1->AxisY->Title = L"Nombres";
			chartArea1->Name = L"ChartArea1";
			this->chart1->ChartAreas->Add(chartArea1);
			legend1->Name = L"Legend1";
			this->chart1->Legends->Add(legend1);
			this->chart1->Location = System::Drawing::Point(12, 398);
			this->chart1->Name = L"chart1";
			series1->BorderWidth = 2;
			series1->ChartArea = L"ChartArea1";
			series1->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::StepLine;
			series1->Legend = L"Legend1";
			series1->LegendText = L"Entrées";
			series1->Name = L"Series1";
			series2->BorderDashStyle = System::Windows::Forms::DataVisualization::Charting::ChartDashStyle::DashDot;
			series2->BorderWidth = 2;
			series2->ChartArea = L"ChartArea1";
			series2->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::StepLine;
			series2->Legend = L"Legend1";
			series2->LegendText = L"Sorties";
			series2->Name = L"Series2";
			series3->BorderDashStyle = System::Windows::Forms::DataVisualization::Charting::ChartDashStyle::Dot;
			series3->BorderWidth = 2;
			series3->ChartArea = L"ChartArea1";
			series3->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::StepLine;
			series3->Legend = L"Legend1";
			series3->LegendText = L"Rejets";
			series3->Name = L"Series3";
			this->chart1->Series->Add(series1);
			this->chart1->Series->Add(series2);
			this->chart1->Series->Add(series3);
			this->chart1->Size = System::Drawing::Size(432, 291);
			this->chart1->TabIndex = 14;
			this->chart1->Text = L"chart1";
			title1->Name = L"Title1";
			title1->Text = L"Sources et sortie";
			this->chart1->Titles->Add(title1);
			// 
			// chart2
			// 
			chartArea2->AxisX->ArrowStyle = System::Windows::Forms::DataVisualization::Charting::AxisArrowStyle::Triangle;
			chartArea2->AxisX->LineDashStyle = System::Windows::Forms::DataVisualization::Charting::ChartDashStyle::Dot;
			chartArea2->AxisX->MajorGrid->Enabled = false;
			chartArea2->AxisX->Minimum = 0;
			chartArea2->AxisX->Title = L"Temps";
			chartArea2->AxisY->ArrowStyle = System::Windows::Forms::DataVisualization::Charting::AxisArrowStyle::Triangle;
			chartArea2->AxisY->MajorGrid->Enabled = false;
			chartArea2->AxisY->Minimum = 0;
			chartArea2->AxisY->Title = L"Temps moyens de séjour";
			chartArea2->Name = L"ChartArea1";
			this->chart2->ChartAreas->Add(chartArea2);
			legend2->Name = L"Legend1";
			this->chart2->Legends->Add(legend2);
			this->chart2->Location = System::Drawing::Point(579, 398);
			this->chart2->Name = L"chart2";
			series4->BorderWidth = 2;
			series4->ChartArea = L"ChartArea1";
			series4->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::StepLine;
			series4->Legend = L"Legend1";
			series4->LegendText = L"Système";
			series4->Name = L"Series1";
			series5->BorderDashStyle = System::Windows::Forms::DataVisualization::Charting::ChartDashStyle::DashDot;
			series5->BorderWidth = 2;
			series5->ChartArea = L"ChartArea1";
			series5->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::StepLine;
			series5->Legend = L"Legend1";
			series5->LegendText = L"File";
			series5->Name = L"Series2";
			series6->BorderDashStyle = System::Windows::Forms::DataVisualization::Charting::ChartDashStyle::Dot;
			series6->BorderWidth = 2;
			series6->ChartArea = L"ChartArea1";
			series6->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::StepLine;
			series6->Legend = L"Legend1";
			series6->LegendText = L"Machine";
			series6->Name = L"Series3";
			this->chart2->Series->Add(series4);
			this->chart2->Series->Add(series5);
			this->chart2->Series->Add(series6);
			this->chart2->Size = System::Drawing::Size(432, 291);
			this->chart2->TabIndex = 16;
			this->chart2->Text = L"chart2";
			title2->Name = L"Title1";
			title2->Text = L"Statistiques";
			this->chart2->Titles->Add(title2);
			// 
			// form_main
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1208, 701);
			this->Controls->Add(this->chart2);
			this->Controls->Add(this->chart1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->richTextBox2);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"form_main";
			this->Text = L"form_main";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart2))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	/*private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {


		System::String^ s_nb_1 = textBox1->Text;
		System::String^ s_nb_2 = textBox2->Text;

		msclr::interop::marshal_context context;
		std::string chaine1 = context.marshal_as<std::string>(s_nb_1);
		std::string chaine2 = context.marshal_as<std::string>(s_nb_2);


		// autre sol
		int nb1 = -1;
		int nb2 = -1;
		std::istringstream(chaine1) >> nb1;
		std::istringstream(chaine2) >> nb2;
		int nb_res = nb1 + nb2;


		// le res. en string
		std::stringstream chaine_res;
		chaine_res << nb_res;
		std::string chaine_res_string = chaine_res.str();

		System::String^ s_nb_res = marshal_as<String^>(chaine_res_string);

		textBox3->Text = s_nb_res;




	}*/
	/* BOUTON "QUITTER" */
	private: System::Void button2_Click_1(System::Object^  sender, System::EventArgs^  e) {
		this->Close();
	}
	/* BOUTON "LANCER SIMULATION" */
	private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
		// nettoyage de la boite de texte et des courbes
		richTextBox2->Text = "";
		chart1->Series[0]->Points->Clear(); 
		chart1->Series[1]->Points->Clear();
		chart1->Series[2]->Points->Clear();
		chart2->Series[0]->Points->Clear();
		chart2->Series[1]->Points->Clear();
		chart2->Series[2]->Points->Clear();

		if (textBox1->Text == "" || textBox2->Text == "" || textBox4->Text == "") {
			richTextBox2->Text = "Veuillez remplir chaque paramètre ci-contre.";
		}
		else {
			/* SIMULATION */
			// lire la durée de la simulation
			int duree = 0;
			duree = int::Parse(textBox1->Text);
			// lire la durée interarrivée
			int DA = 0;
			DA = int::Parse(textBox2->Text);
			// lire la durée de traitement
			int DT = 0;
			DT = int::Parse(textBox4->Text);

			t_systeme systeme = { {VIDE} };
			richTextBox2->Text = "Lancement de la simulation...\n";
			simuler(duree, DA, DT, systeme);

			/* AFFICHAGE STATS PIECES */
			t_sortie& s = systeme.s;
			System::String^ donneeSysteme =
				"TempsMoyenDeSejourDansLeSysteme = " + s.tempsMoyenSys + "\n" +
				"TempsMoyenDeSejourDansLaFile = " + s.tempsMoyenFile + "\n" +
				"TempsMoyenDeSejourSurLaMachine = " + s.tempsMoyenMachine + "\n" +
				"NombreMoyenDePiecesSurLaFile = " + systeme.f.nbPiecesMoyen + "\n";
			richTextBox2->AppendText(donneeSysteme);
			for (int i = 1; i <= NBPIECES; i++) {
				System::Windows::Forms::Application::DoEvents();
				t_piece& p = systeme.pieces[i];
				System::String^ donneePiece = "" + p.num + " " +
					p.dateEntreeSys + " " + p.dateSortieSys + "\n";
				richTextBox2->AppendText(donneePiece);
			}
			richTextBox2->AppendText("Fin de simulation.");

			/* TRACAGE DE COURBES */
			int nbPieces = systeme.s.nbPieceSortie + systeme.e.nbPiecesPerdues;
			// variables courbe "Source et sortie"
			int y_nbPiecesEntree = 0,
				y_nbPiecesSortie = 0,
				y_nbPiecesRejetees = 0;
			// variables courbe "Statistiques"
			float y_sejourMoySys = .0f,
				y_sejourMoyFile = .0f,
				y_sejourMoyMachine = .0f;

			chart1->Series[0]->Points->AddXY(0, 0);
			chart1->Series[1]->Points->AddXY(0, 0);
			chart1->Series[2]->Points->AddXY(0, 0);
			for (int iPiece = 1; iPiece <= nbPieces; iPiece++) {
				t_piece& p = systeme.pieces[iPiece];
				if (p.dateEntreeSys > 0 || p.num == 1) {
					y_nbPiecesEntree++;
				}

				if (p.dateSortieSys > 0) {
					y_sejourMoySys *= y_nbPiecesSortie;
					y_sejourMoyFile *= y_nbPiecesSortie;
					y_sejourMoyMachine *= y_nbPiecesSortie;

					y_nbPiecesSortie++;

					y_sejourMoySys += (p.dateSortieSys - p.dateEntreeSys);
					y_sejourMoySys /= y_nbPiecesSortie;
					y_sejourMoyFile += (p.dateSortieFile - p.dateEntreeFile);
					y_sejourMoyFile /= y_nbPiecesSortie;
					y_sejourMoyMachine += (p.dateSortieMachine - p.dateEntreeMachine);
					y_sejourMoyMachine /= y_nbPiecesSortie;
				}
				else {
					y_nbPiecesRejetees++;
				}

				chart1->Series[0]->Points->AddXY(p.dateEntreeSys, y_nbPiecesEntree);
				chart1->Series[1]->Points->AddXY(p.dateEntreeSys + DT, y_nbPiecesSortie);
				chart1->Series[2]->Points->AddXY(p.dateEntreeSys, y_nbPiecesRejetees);

				chart2->Series[0]->Points->AddXY(p.dateEntreeSys, y_sejourMoySys);
				chart2->Series[1]->Points->AddXY(p.dateEntreeSys, y_sejourMoyFile);
				chart2->Series[2]->Points->AddXY(p.dateEntreeSys, y_sejourMoyMachine);
			}
		}
	}
};
}
