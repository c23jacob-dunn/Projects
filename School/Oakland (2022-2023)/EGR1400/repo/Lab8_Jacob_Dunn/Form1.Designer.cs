namespace Lab8_Jacob_Dunn
{
    partial class Form1
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            this.bindingSource1 = new System.Windows.Forms.BindingSource(this.components);
            this.medicalRecords1400DataSet = new Lab8_Jacob_Dunn.MedicalRecords1400DataSet();
            this.medicalRecordsTableAdapter = new Lab8_Jacob_Dunn.MedicalRecords1400DataSetTableAdapters.MedicalRecordsTableAdapter();
            this.lstDisplay = new System.Windows.Forms.ListBox();
            this.btnAnalyze = new System.Windows.Forms.Button();
            ((System.ComponentModel.ISupportInitialize)(this.bindingSource1)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.medicalRecords1400DataSet)).BeginInit();
            this.SuspendLayout();
            // 
            // bindingSource1
            // 
            this.bindingSource1.DataMember = "MedicalRecords";
            this.bindingSource1.DataSource = this.medicalRecords1400DataSet;
            // 
            // medicalRecords1400DataSet
            // 
            this.medicalRecords1400DataSet.DataSetName = "MedicalRecords1400DataSet";
            this.medicalRecords1400DataSet.SchemaSerializationMode = System.Data.SchemaSerializationMode.IncludeSchema;
            // 
            // medicalRecordsTableAdapter
            // 
            this.medicalRecordsTableAdapter.ClearBeforeFill = true;
            // 
            // lstDisplay
            // 
            this.lstDisplay.FormattingEnabled = true;
            this.lstDisplay.ItemHeight = 20;
            this.lstDisplay.Location = new System.Drawing.Point(12, 14);
            this.lstDisplay.Name = "lstDisplay";
            this.lstDisplay.Size = new System.Drawing.Size(440, 404);
            this.lstDisplay.TabIndex = 0;
            // 
            // btnAnalyze
            // 
            this.btnAnalyze.Location = new System.Drawing.Point(513, 170);
            this.btnAnalyze.Name = "btnAnalyze";
            this.btnAnalyze.Size = new System.Drawing.Size(187, 86);
            this.btnAnalyze.TabIndex = 1;
            this.btnAnalyze.Text = "Analyze";
            this.btnAnalyze.UseVisualStyleBackColor = true;
            this.btnAnalyze.Click += new System.EventHandler(this.btnAnalyze_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(9F, 20F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.btnAnalyze);
            this.Controls.Add(this.lstDisplay);
            this.Name = "Form1";
            this.Text = "Form1";
            this.Load += new System.EventHandler(this.Form1_Load);
            ((System.ComponentModel.ISupportInitialize)(this.bindingSource1)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.medicalRecords1400DataSet)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.BindingSource bindingSource1;
        private MedicalRecords1400DataSet medicalRecords1400DataSet;
        private MedicalRecords1400DataSetTableAdapters.MedicalRecordsTableAdapter medicalRecordsTableAdapter;
        private System.Windows.Forms.ListBox lstDisplay;
        private System.Windows.Forms.Button btnAnalyze;
    }
}

