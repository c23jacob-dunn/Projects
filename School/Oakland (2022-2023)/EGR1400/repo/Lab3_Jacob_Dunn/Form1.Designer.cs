namespace Lab3_Jacob_Dunn
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
            this.grpboxGender = new System.Windows.Forms.GroupBox();
            this.radFemale = new System.Windows.Forms.RadioButton();
            this.radMale = new System.Windows.Forms.RadioButton();
            this.grpboxAge = new System.Windows.Forms.GroupBox();
            this.radOver30 = new System.Windows.Forms.RadioButton();
            this.radUnder30 = new System.Windows.Forms.RadioButton();
            this.grpboxWeight = new System.Windows.Forms.GroupBox();
            this.lblPounds = new System.Windows.Forms.Label();
            this.txtWeight = new System.Windows.Forms.TextBox();
            this.grpboxMeasurements = new System.Windows.Forms.GroupBox();
            this.lblFCalf = new System.Windows.Forms.Label();
            this.lblFThigh = new System.Windows.Forms.Label();
            this.lblFWrist = new System.Windows.Forms.Label();
            this.lblFHips = new System.Windows.Forms.Label();
            this.txtMeas4 = new System.Windows.Forms.TextBox();
            this.txtMeas3 = new System.Windows.Forms.TextBox();
            this.txtMeas2 = new System.Windows.Forms.TextBox();
            this.txtMeas1 = new System.Windows.Forms.TextBox();
            this.lblMWrist = new System.Windows.Forms.Label();
            this.lblMForearm = new System.Windows.Forms.Label();
            this.lblMHips = new System.Windows.Forms.Label();
            this.lblMWaist = new System.Windows.Forms.Label();
            this.grpboxResults = new System.Windows.Forms.GroupBox();
            this.txtResults1 = new System.Windows.Forms.TextBox();
            this.btnCalculate = new System.Windows.Forms.Button();
            this.btnExit = new System.Windows.Forms.Button();
            this.btnReset = new System.Windows.Forms.Button();
            this.grpboxGender.SuspendLayout();
            this.grpboxAge.SuspendLayout();
            this.grpboxWeight.SuspendLayout();
            this.grpboxMeasurements.SuspendLayout();
            this.grpboxResults.SuspendLayout();
            this.SuspendLayout();
            // 
            // grpboxGender
            // 
            this.grpboxGender.Controls.Add(this.radFemale);
            this.grpboxGender.Controls.Add(this.radMale);
            this.grpboxGender.Location = new System.Drawing.Point(63, 12);
            this.grpboxGender.Name = "grpboxGender";
            this.grpboxGender.Size = new System.Drawing.Size(195, 61);
            this.grpboxGender.TabIndex = 0;
            this.grpboxGender.TabStop = false;
            this.grpboxGender.Text = "Gender";
            // 
            // radFemale
            // 
            this.radFemale.AutoSize = true;
            this.radFemale.Location = new System.Drawing.Point(96, 20);
            this.radFemale.Name = "radFemale";
            this.radFemale.Size = new System.Drawing.Size(87, 24);
            this.radFemale.TabIndex = 1;
            this.radFemale.TabStop = true;
            this.radFemale.Text = "Female";
            this.radFemale.UseVisualStyleBackColor = true;
            this.radFemale.CheckedChanged += new System.EventHandler(this.radFemale_CheckedChanged);
            // 
            // radMale
            // 
            this.radMale.AutoSize = true;
            this.radMale.Location = new System.Drawing.Point(7, 21);
            this.radMale.Name = "radMale";
            this.radMale.Size = new System.Drawing.Size(68, 24);
            this.radMale.TabIndex = 0;
            this.radMale.TabStop = true;
            this.radMale.Text = "Male";
            this.radMale.UseVisualStyleBackColor = true;
            this.radMale.CheckedChanged += new System.EventHandler(this.radMale_CheckedChanged);
            // 
            // grpboxAge
            // 
            this.grpboxAge.Controls.Add(this.radOver30);
            this.grpboxAge.Controls.Add(this.radUnder30);
            this.grpboxAge.Location = new System.Drawing.Point(322, 12);
            this.grpboxAge.Name = "grpboxAge";
            this.grpboxAge.Size = new System.Drawing.Size(269, 61);
            this.grpboxAge.TabIndex = 1;
            this.grpboxAge.TabStop = false;
            this.grpboxAge.Text = "Age";
            // 
            // radOver30
            // 
            this.radOver30.AutoSize = true;
            this.radOver30.Location = new System.Drawing.Point(160, 21);
            this.radOver30.Name = "radOver30";
            this.radOver30.Size = new System.Drawing.Size(89, 24);
            this.radOver30.TabIndex = 1;
            this.radOver30.TabStop = true;
            this.radOver30.Text = "Over 30";
            this.radOver30.UseVisualStyleBackColor = true;
            // 
            // radUnder30
            // 
            this.radUnder30.AutoSize = true;
            this.radUnder30.Location = new System.Drawing.Point(7, 21);
            this.radUnder30.Name = "radUnder30";
            this.radUnder30.Size = new System.Drawing.Size(131, 24);
            this.radUnder30.TabIndex = 0;
            this.radUnder30.TabStop = true;
            this.radUnder30.Text = "30 and Under";
            this.radUnder30.UseVisualStyleBackColor = true;
            // 
            // grpboxWeight
            // 
            this.grpboxWeight.Controls.Add(this.lblPounds);
            this.grpboxWeight.Controls.Add(this.txtWeight);
            this.grpboxWeight.Location = new System.Drawing.Point(653, 12);
            this.grpboxWeight.Name = "grpboxWeight";
            this.grpboxWeight.Size = new System.Drawing.Size(198, 61);
            this.grpboxWeight.TabIndex = 2;
            this.grpboxWeight.TabStop = false;
            this.grpboxWeight.Text = "Weight";
            // 
            // lblPounds
            // 
            this.lblPounds.AutoSize = true;
            this.lblPounds.Location = new System.Drawing.Point(112, 31);
            this.lblPounds.Name = "lblPounds";
            this.lblPounds.Size = new System.Drawing.Size(63, 20);
            this.lblPounds.TabIndex = 1;
            this.lblPounds.Text = "Pounds";
            // 
            // txtWeight
            // 
            this.txtWeight.Location = new System.Drawing.Point(6, 25);
            this.txtWeight.Name = "txtWeight";
            this.txtWeight.Size = new System.Drawing.Size(100, 26);
            this.txtWeight.TabIndex = 0;
            // 
            // grpboxMeasurements
            // 
            this.grpboxMeasurements.Controls.Add(this.lblFCalf);
            this.grpboxMeasurements.Controls.Add(this.lblFThigh);
            this.grpboxMeasurements.Controls.Add(this.lblFWrist);
            this.grpboxMeasurements.Controls.Add(this.lblFHips);
            this.grpboxMeasurements.Controls.Add(this.txtMeas4);
            this.grpboxMeasurements.Controls.Add(this.txtMeas3);
            this.grpboxMeasurements.Controls.Add(this.txtMeas2);
            this.grpboxMeasurements.Controls.Add(this.txtMeas1);
            this.grpboxMeasurements.Controls.Add(this.lblMWrist);
            this.grpboxMeasurements.Controls.Add(this.lblMForearm);
            this.grpboxMeasurements.Controls.Add(this.lblMHips);
            this.grpboxMeasurements.Controls.Add(this.lblMWaist);
            this.grpboxMeasurements.Location = new System.Drawing.Point(12, 79);
            this.grpboxMeasurements.Name = "grpboxMeasurements";
            this.grpboxMeasurements.Size = new System.Drawing.Size(862, 247);
            this.grpboxMeasurements.TabIndex = 3;
            this.grpboxMeasurements.TabStop = false;
            this.grpboxMeasurements.Text = "Measurement in inches";
            // 
            // lblFCalf
            // 
            this.lblFCalf.AutoSize = true;
            this.lblFCalf.Location = new System.Drawing.Point(183, 154);
            this.lblFCalf.Name = "lblFCalf";
            this.lblFCalf.Size = new System.Drawing.Size(653, 20);
            this.lblFCalf.TabIndex = 11;
            this.lblFCalf.Text = "Calf - Stand with weight on both feet, measure widest part midway between knee an" +
    "d ankle.";
            this.lblFCalf.Visible = false;
            // 
            // lblFThigh
            // 
            this.lblFThigh.AutoSize = true;
            this.lblFThigh.Location = new System.Drawing.Point(180, 99);
            this.lblFThigh.Name = "lblFThigh";
            this.lblFThigh.Size = new System.Drawing.Size(538, 20);
            this.lblFThigh.TabIndex = 10;
            this.lblFThigh.Text = "Thigh - Stand with feet 12 inches apart, measure widest part of upper thigh.";
            this.lblFThigh.Visible = false;
            // 
            // lblFWrist
            // 
            this.lblFWrist.AutoSize = true;
            this.lblFWrist.Location = new System.Drawing.Point(180, 210);
            this.lblFWrist.Name = "lblFWrist";
            this.lblFWrist.Size = new System.Drawing.Size(464, 20);
            this.lblFWrist.TabIndex = 9;
            this.lblFWrist.Text = "Wrist - Measure just above bony protuberance towards the hand.";
            this.lblFWrist.Visible = false;
            // 
            // lblFHips
            // 
            this.lblFHips.AutoSize = true;
            this.lblFHips.Location = new System.Drawing.Point(180, 50);
            this.lblFHips.Name = "lblFHips";
            this.lblFHips.Size = new System.Drawing.Size(573, 20);
            this.lblFHips.TabIndex = 8;
            this.lblFHips.Text = "Hips - Feet 4 inches apart, measure greatest circumfrance around hips and butt.";
            this.lblFHips.Visible = false;
            // 
            // txtMeas4
            // 
            this.txtMeas4.Location = new System.Drawing.Point(21, 210);
            this.txtMeas4.Name = "txtMeas4";
            this.txtMeas4.Size = new System.Drawing.Size(100, 26);
            this.txtMeas4.TabIndex = 7;
            // 
            // txtMeas3
            // 
            this.txtMeas3.Location = new System.Drawing.Point(21, 154);
            this.txtMeas3.Name = "txtMeas3";
            this.txtMeas3.Size = new System.Drawing.Size(100, 26);
            this.txtMeas3.TabIndex = 6;
            // 
            // txtMeas2
            // 
            this.txtMeas2.Location = new System.Drawing.Point(21, 99);
            this.txtMeas2.Name = "txtMeas2";
            this.txtMeas2.Size = new System.Drawing.Size(100, 26);
            this.txtMeas2.TabIndex = 5;
            // 
            // txtMeas1
            // 
            this.txtMeas1.Location = new System.Drawing.Point(21, 47);
            this.txtMeas1.Name = "txtMeas1";
            this.txtMeas1.Size = new System.Drawing.Size(100, 26);
            this.txtMeas1.TabIndex = 4;
            // 
            // lblMWrist
            // 
            this.lblMWrist.AutoSize = true;
            this.lblMWrist.Location = new System.Drawing.Point(180, 210);
            this.lblMWrist.Name = "lblMWrist";
            this.lblMWrist.Size = new System.Drawing.Size(464, 20);
            this.lblMWrist.TabIndex = 3;
            this.lblMWrist.Text = "Wrist - Measure just above bony protuberance towards the hand.";
            // 
            // lblMForearm
            // 
            this.lblMForearm.AutoSize = true;
            this.lblMForearm.Location = new System.Drawing.Point(180, 154);
            this.lblMForearm.Name = "lblMForearm";
            this.lblMForearm.Size = new System.Drawing.Size(477, 20);
            this.lblMForearm.TabIndex = 2;
            this.lblMForearm.Text = "Forearm - Clench fist, measure widest part between fist and elbow.";
            // 
            // lblMHips
            // 
            this.lblMHips.AutoSize = true;
            this.lblMHips.Location = new System.Drawing.Point(180, 99);
            this.lblMHips.Name = "lblMHips";
            this.lblMHips.Size = new System.Drawing.Size(573, 20);
            this.lblMHips.TabIndex = 1;
            this.lblMHips.Text = "Hips - Feet 4 inches apart, measure greatest circumfrance around hips and butt.";
            // 
            // lblMWaist
            // 
            this.lblMWaist.AutoSize = true;
            this.lblMWaist.Location = new System.Drawing.Point(180, 47);
            this.lblMWaist.Name = "lblMWaist";
            this.lblMWaist.Size = new System.Drawing.Size(482, 20);
            this.lblMWaist.TabIndex = 0;
            this.lblMWaist.Text = "Waist - Measure at greatest circumfrance, relaxed and comfortable.";
            // 
            // grpboxResults
            // 
            this.grpboxResults.Controls.Add(this.txtResults1);
            this.grpboxResults.Location = new System.Drawing.Point(180, 332);
            this.grpboxResults.Name = "grpboxResults";
            this.grpboxResults.Size = new System.Drawing.Size(694, 120);
            this.grpboxResults.TabIndex = 4;
            this.grpboxResults.TabStop = false;
            this.grpboxResults.Text = "Results";
            // 
            // txtResults1
            // 
            this.txtResults1.Location = new System.Drawing.Point(6, 25);
            this.txtResults1.Multiline = true;
            this.txtResults1.Name = "txtResults1";
            this.txtResults1.ReadOnly = true;
            this.txtResults1.Size = new System.Drawing.Size(665, 89);
            this.txtResults1.TabIndex = 0;
            this.txtResults1.TextChanged += new System.EventHandler(this.txtResults_TextChanged);
            // 
            // btnCalculate
            // 
            this.btnCalculate.Location = new System.Drawing.Point(17, 329);
            this.btnCalculate.Name = "btnCalculate";
            this.btnCalculate.Size = new System.Drawing.Size(121, 37);
            this.btnCalculate.TabIndex = 5;
            this.btnCalculate.Text = "Calculate";
            this.btnCalculate.UseVisualStyleBackColor = true;
            this.btnCalculate.Click += new System.EventHandler(this.btnCalculate_Click);
            // 
            // btnExit
            // 
            this.btnExit.Location = new System.Drawing.Point(17, 415);
            this.btnExit.Name = "btnExit";
            this.btnExit.Size = new System.Drawing.Size(121, 37);
            this.btnExit.TabIndex = 6;
            this.btnExit.Text = "Exit";
            this.btnExit.UseVisualStyleBackColor = true;
            this.btnExit.Click += new System.EventHandler(this.btnExit_Click);
            // 
            // btnReset
            // 
            this.btnReset.Location = new System.Drawing.Point(17, 372);
            this.btnReset.Name = "btnReset";
            this.btnReset.Size = new System.Drawing.Size(121, 37);
            this.btnReset.TabIndex = 7;
            this.btnReset.Text = "Reset";
            this.btnReset.UseVisualStyleBackColor = true;
            this.btnReset.Click += new System.EventHandler(this.btnReset_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(9F, 20F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(886, 463);
            this.Controls.Add(this.btnReset);
            this.Controls.Add(this.btnExit);
            this.Controls.Add(this.btnCalculate);
            this.Controls.Add(this.grpboxResults);
            this.Controls.Add(this.grpboxMeasurements);
            this.Controls.Add(this.grpboxWeight);
            this.Controls.Add(this.grpboxAge);
            this.Controls.Add(this.grpboxGender);
            this.Name = "Form1";
            this.Text = "Covert Bailey\'s Tape-Measure Fat Formula";
            this.grpboxGender.ResumeLayout(false);
            this.grpboxGender.PerformLayout();
            this.grpboxAge.ResumeLayout(false);
            this.grpboxAge.PerformLayout();
            this.grpboxWeight.ResumeLayout(false);
            this.grpboxWeight.PerformLayout();
            this.grpboxMeasurements.ResumeLayout(false);
            this.grpboxMeasurements.PerformLayout();
            this.grpboxResults.ResumeLayout(false);
            this.grpboxResults.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.GroupBox grpboxGender;
        private System.Windows.Forms.RadioButton radFemale;
        private System.Windows.Forms.RadioButton radMale;
        private System.Windows.Forms.GroupBox grpboxAge;
        private System.Windows.Forms.RadioButton radOver30;
        private System.Windows.Forms.RadioButton radUnder30;
        private System.Windows.Forms.GroupBox grpboxWeight;
        private System.Windows.Forms.Label lblPounds;
        private System.Windows.Forms.TextBox txtWeight;
        private System.Windows.Forms.GroupBox grpboxMeasurements;
        private System.Windows.Forms.TextBox txtMeas4;
        private System.Windows.Forms.TextBox txtMeas3;
        private System.Windows.Forms.TextBox txtMeas2;
        private System.Windows.Forms.TextBox txtMeas1;
        private System.Windows.Forms.Label lblMWrist;
        private System.Windows.Forms.Label lblMForearm;
        private System.Windows.Forms.Label lblMHips;
        private System.Windows.Forms.Label lblMWaist;
        private System.Windows.Forms.GroupBox grpboxResults;
        private System.Windows.Forms.TextBox txtResults1;
        private System.Windows.Forms.Button btnCalculate;
        private System.Windows.Forms.Button btnExit;
        private System.Windows.Forms.Label lblFHips;
        private System.Windows.Forms.Label lblFCalf;
        private System.Windows.Forms.Label lblFThigh;
        private System.Windows.Forms.Label lblFWrist;
        private System.Windows.Forms.Button btnReset;
    }
}

