namespace Lab5_Jacob_Dunn
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Form1));
            this.tbrVoltage = new System.Windows.Forms.TrackBar();
            this.btnCalc = new System.Windows.Forms.Button();
            this.picCircuit2 = new System.Windows.Forms.PictureBox();
            this.picCircuit1 = new System.Windows.Forms.PictureBox();
            this.chbxRemoveTrackBar = new System.Windows.Forms.CheckBox();
            this.chbxRemoveR3 = new System.Windows.Forms.CheckBox();
            this.txtVoltage = new System.Windows.Forms.TextBox();
            this.lblR1 = new System.Windows.Forms.Label();
            this.txtR1 = new System.Windows.Forms.TextBox();
            this.txtV1 = new System.Windows.Forms.TextBox();
            this.lblV1 = new System.Windows.Forms.Label();
            this.lblV3 = new System.Windows.Forms.Label();
            this.txtV3 = new System.Windows.Forms.TextBox();
            this.txtR3 = new System.Windows.Forms.TextBox();
            this.lblR3 = new System.Windows.Forms.Label();
            this.lblV2 = new System.Windows.Forms.Label();
            this.txtV2 = new System.Windows.Forms.TextBox();
            this.txtR2 = new System.Windows.Forms.TextBox();
            this.lblR2 = new System.Windows.Forms.Label();
            this.lblI = new System.Windows.Forms.Label();
            this.txtI = new System.Windows.Forms.TextBox();
            this.txtIDirection = new System.Windows.Forms.TextBox();
            this.lblPower = new System.Windows.Forms.Label();
            this.lblWatts = new System.Windows.Forms.Label();
            this.txtPower = new System.Windows.Forms.TextBox();
            this.txtI2 = new System.Windows.Forms.TextBox();
            this.lblI2 = new System.Windows.Forms.Label();
            this.label1 = new System.Windows.Forms.Label();
            ((System.ComponentModel.ISupportInitialize)(this.tbrVoltage)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.picCircuit2)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.picCircuit1)).BeginInit();
            this.SuspendLayout();
            // 
            // tbrVoltage
            // 
            this.tbrVoltage.BackColor = System.Drawing.Color.Red;
            this.tbrVoltage.Location = new System.Drawing.Point(12, 12);
            this.tbrVoltage.Minimum = 1;
            this.tbrVoltage.Name = "tbrVoltage";
            this.tbrVoltage.Orientation = System.Windows.Forms.Orientation.Vertical;
            this.tbrVoltage.Size = new System.Drawing.Size(69, 351);
            this.tbrVoltage.TabIndex = 0;
            this.tbrVoltage.Value = 4;
            this.tbrVoltage.Scroll += new System.EventHandler(this.tbrVoltage_Scroll);
            // 
            // btnCalc
            // 
            this.btnCalc.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(0)))), ((int)(((byte)(192)))), ((int)(((byte)(0)))));
            this.btnCalc.Location = new System.Drawing.Point(12, 379);
            this.btnCalc.Name = "btnCalc";
            this.btnCalc.Size = new System.Drawing.Size(776, 59);
            this.btnCalc.TabIndex = 1;
            this.btnCalc.Text = "Calculate";
            this.btnCalc.UseVisualStyleBackColor = false;
            this.btnCalc.Click += new System.EventHandler(this.btnCalc_Click);
            // 
            // picCircuit2
            // 
            this.picCircuit2.Image = ((System.Drawing.Image)(resources.GetObject("picCircuit2.Image")));
            this.picCircuit2.Location = new System.Drawing.Point(205, 99);
            this.picCircuit2.Name = "picCircuit2";
            this.picCircuit2.Size = new System.Drawing.Size(417, 214);
            this.picCircuit2.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.picCircuit2.TabIndex = 2;
            this.picCircuit2.TabStop = false;
            this.picCircuit2.Visible = false;
            // 
            // picCircuit1
            // 
            this.picCircuit1.Image = ((System.Drawing.Image)(resources.GetObject("picCircuit1.Image")));
            this.picCircuit1.Location = new System.Drawing.Point(205, 99);
            this.picCircuit1.Name = "picCircuit1";
            this.picCircuit1.Size = new System.Drawing.Size(417, 214);
            this.picCircuit1.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.picCircuit1.TabIndex = 3;
            this.picCircuit1.TabStop = false;
            // 
            // chbxRemoveTrackBar
            // 
            this.chbxRemoveTrackBar.AutoSize = true;
            this.chbxRemoveTrackBar.Location = new System.Drawing.Point(200, 339);
            this.chbxRemoveTrackBar.Name = "chbxRemoveTrackBar";
            this.chbxRemoveTrackBar.Size = new System.Drawing.Size(160, 24);
            this.chbxRemoveTrackBar.TabIndex = 4;
            this.chbxRemoveTrackBar.Text = "Remove Trackbar";
            this.chbxRemoveTrackBar.UseVisualStyleBackColor = true;
            this.chbxRemoveTrackBar.CheckedChanged += new System.EventHandler(this.chbxRemoveTrackBar_CheckedChanged);
            // 
            // chbxRemoveR3
            // 
            this.chbxRemoveR3.AutoSize = true;
            this.chbxRemoveR3.Location = new System.Drawing.Point(437, 339);
            this.chbxRemoveR3.Name = "chbxRemoveR3";
            this.chbxRemoveR3.Size = new System.Drawing.Size(203, 24);
            this.chbxRemoveR3.TabIndex = 5;
            this.chbxRemoveR3.Text = "Remove R3 from Circuit";
            this.chbxRemoveR3.UseVisualStyleBackColor = true;
            this.chbxRemoveR3.CheckedChanged += new System.EventHandler(this.chbxRemoveR3_CheckedChanged);
            // 
            // txtVoltage
            // 
            this.txtVoltage.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(192)))), ((int)(((byte)(0)))), ((int)(((byte)(192)))));
            this.txtVoltage.Font = new System.Drawing.Font("Microsoft Sans Serif", 22F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.txtVoltage.ForeColor = System.Drawing.Color.White;
            this.txtVoltage.Location = new System.Drawing.Point(87, 237);
            this.txtVoltage.Multiline = true;
            this.txtVoltage.Name = "txtVoltage";
            this.txtVoltage.Size = new System.Drawing.Size(112, 61);
            this.txtVoltage.TabIndex = 6;
            this.txtVoltage.Text = "4";
            this.txtVoltage.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // lblR1
            // 
            this.lblR1.AutoSize = true;
            this.lblR1.BackColor = System.Drawing.Color.Red;
            this.lblR1.Location = new System.Drawing.Point(401, 34);
            this.lblR1.Name = "lblR1";
            this.lblR1.Size = new System.Drawing.Size(30, 20);
            this.lblR1.TabIndex = 7;
            this.lblR1.Text = "R1";
            // 
            // txtR1
            // 
            this.txtR1.Location = new System.Drawing.Point(437, 31);
            this.txtR1.Name = "txtR1";
            this.txtR1.Size = new System.Drawing.Size(100, 26);
            this.txtR1.TabIndex = 8;
            this.txtR1.Text = "100";
            this.txtR1.TextChanged += new System.EventHandler(this.txtR1_TextChanged);
            // 
            // txtV1
            // 
            this.txtV1.BackColor = System.Drawing.SystemColors.ActiveCaption;
            this.txtV1.Location = new System.Drawing.Point(437, 63);
            this.txtV1.Name = "txtV1";
            this.txtV1.ReadOnly = true;
            this.txtV1.Size = new System.Drawing.Size(100, 26);
            this.txtV1.TabIndex = 9;
            this.txtV1.Text = "1.6";
            // 
            // lblV1
            // 
            this.lblV1.AutoSize = true;
            this.lblV1.BackColor = System.Drawing.SystemColors.ActiveCaption;
            this.lblV1.Location = new System.Drawing.Point(402, 66);
            this.lblV1.Name = "lblV1";
            this.lblV1.Size = new System.Drawing.Size(29, 20);
            this.lblV1.TabIndex = 10;
            this.lblV1.Text = "V1";
            // 
            // lblV3
            // 
            this.lblV3.AutoSize = true;
            this.lblV3.BackColor = System.Drawing.SystemColors.ActiveCaption;
            this.lblV3.Location = new System.Drawing.Point(335, 220);
            this.lblV3.Name = "lblV3";
            this.lblV3.Size = new System.Drawing.Size(29, 20);
            this.lblV3.TabIndex = 14;
            this.lblV3.Text = "V3";
            // 
            // txtV3
            // 
            this.txtV3.BackColor = System.Drawing.SystemColors.ActiveCaption;
            this.txtV3.Location = new System.Drawing.Point(370, 217);
            this.txtV3.Name = "txtV3";
            this.txtV3.ReadOnly = true;
            this.txtV3.Size = new System.Drawing.Size(100, 26);
            this.txtV3.TabIndex = 13;
            this.txtV3.Text = "4";
            // 
            // txtR3
            // 
            this.txtR3.Location = new System.Drawing.Point(370, 185);
            this.txtR3.Name = "txtR3";
            this.txtR3.Size = new System.Drawing.Size(100, 26);
            this.txtR3.TabIndex = 12;
            this.txtR3.Text = "150";
            this.txtR3.TextChanged += new System.EventHandler(this.txtR3_TextChanged);
            // 
            // lblR3
            // 
            this.lblR3.AutoSize = true;
            this.lblR3.BackColor = System.Drawing.Color.Red;
            this.lblR3.Location = new System.Drawing.Point(334, 188);
            this.lblR3.Name = "lblR3";
            this.lblR3.Size = new System.Drawing.Size(30, 20);
            this.lblR3.TabIndex = 11;
            this.lblR3.Text = "R3";
            // 
            // lblV2
            // 
            this.lblV2.AutoSize = true;
            this.lblV2.BackColor = System.Drawing.SystemColors.ActiveCaption;
            this.lblV2.Location = new System.Drawing.Point(634, 204);
            this.lblV2.Name = "lblV2";
            this.lblV2.Size = new System.Drawing.Size(29, 20);
            this.lblV2.TabIndex = 18;
            this.lblV2.Text = "V2";
            // 
            // txtV2
            // 
            this.txtV2.BackColor = System.Drawing.SystemColors.ActiveCaption;
            this.txtV2.Location = new System.Drawing.Point(669, 201);
            this.txtV2.Name = "txtV2";
            this.txtV2.ReadOnly = true;
            this.txtV2.Size = new System.Drawing.Size(100, 26);
            this.txtV2.TabIndex = 17;
            this.txtV2.Text = "2.4";
            // 
            // txtR2
            // 
            this.txtR2.Location = new System.Drawing.Point(669, 169);
            this.txtR2.Name = "txtR2";
            this.txtR2.Size = new System.Drawing.Size(100, 26);
            this.txtR2.TabIndex = 16;
            this.txtR2.Text = "150";
            this.txtR2.TextChanged += new System.EventHandler(this.txtR2_TextChanged);
            // 
            // lblR2
            // 
            this.lblR2.AutoSize = true;
            this.lblR2.BackColor = System.Drawing.Color.Red;
            this.lblR2.Location = new System.Drawing.Point(633, 169);
            this.lblR2.Name = "lblR2";
            this.lblR2.Size = new System.Drawing.Size(30, 20);
            this.lblR2.TabIndex = 15;
            this.lblR2.Text = "R2";
            // 
            // lblI
            // 
            this.lblI.AutoSize = true;
            this.lblI.BackColor = System.Drawing.Color.Yellow;
            this.lblI.Location = new System.Drawing.Point(196, 37);
            this.lblI.Name = "lblI";
            this.lblI.Size = new System.Drawing.Size(14, 20);
            this.lblI.TabIndex = 20;
            this.lblI.Text = "I";
            // 
            // txtI
            // 
            this.txtI.BackColor = System.Drawing.Color.Yellow;
            this.txtI.Location = new System.Drawing.Point(216, 35);
            this.txtI.Name = "txtI";
            this.txtI.ReadOnly = true;
            this.txtI.Size = new System.Drawing.Size(100, 26);
            this.txtI.TabIndex = 21;
            this.txtI.Text = "0.0427";
            // 
            // txtIDirection
            // 
            this.txtIDirection.Location = new System.Drawing.Point(216, 67);
            this.txtIDirection.Name = "txtIDirection";
            this.txtIDirection.Size = new System.Drawing.Size(100, 26);
            this.txtIDirection.TabIndex = 22;
            this.txtIDirection.Text = "  --------------->";
            // 
            // lblPower
            // 
            this.lblPower.AutoSize = true;
            this.lblPower.Location = new System.Drawing.Point(444, 339);
            this.lblPower.Name = "lblPower";
            this.lblPower.Size = new System.Drawing.Size(53, 20);
            this.lblPower.TabIndex = 23;
            this.lblPower.Text = "Power";
            this.lblPower.Visible = false;
            // 
            // lblWatts
            // 
            this.lblWatts.AutoSize = true;
            this.lblWatts.Location = new System.Drawing.Point(612, 340);
            this.lblWatts.Name = "lblWatts";
            this.lblWatts.Size = new System.Drawing.Size(51, 20);
            this.lblWatts.TabIndex = 24;
            this.lblWatts.Text = "Watts";
            this.lblWatts.Visible = false;
            // 
            // txtPower
            // 
            this.txtPower.Location = new System.Drawing.Point(503, 337);
            this.txtPower.Name = "txtPower";
            this.txtPower.Size = new System.Drawing.Size(100, 26);
            this.txtPower.TabIndex = 25;
            this.txtPower.Visible = false;
            // 
            // txtI2
            // 
            this.txtI2.BackColor = System.Drawing.Color.Yellow;
            this.txtI2.Location = new System.Drawing.Point(669, 237);
            this.txtI2.Name = "txtI2";
            this.txtI2.ReadOnly = true;
            this.txtI2.Size = new System.Drawing.Size(100, 26);
            this.txtI2.TabIndex = 27;
            this.txtI2.Text = "0.0427";
            this.txtI2.Visible = false;
            // 
            // lblI2
            // 
            this.lblI2.AutoSize = true;
            this.lblI2.BackColor = System.Drawing.Color.Yellow;
            this.lblI2.Location = new System.Drawing.Point(649, 240);
            this.lblI2.Name = "lblI2";
            this.lblI2.Size = new System.Drawing.Size(14, 20);
            this.lblI2.TabIndex = 26;
            this.lblI2.Text = "I";
            this.lblI2.Visible = false;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Microsoft Sans Serif", 8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label1.Location = new System.Drawing.Point(83, 207);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(119, 20);
            this.label1.TabIndex = 28;
            this.label1.Text = "Source Voltage";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(9F, 20F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.txtI2);
            this.Controls.Add(this.lblI2);
            this.Controls.Add(this.txtPower);
            this.Controls.Add(this.lblWatts);
            this.Controls.Add(this.lblPower);
            this.Controls.Add(this.txtIDirection);
            this.Controls.Add(this.txtI);
            this.Controls.Add(this.lblI);
            this.Controls.Add(this.lblV2);
            this.Controls.Add(this.txtV2);
            this.Controls.Add(this.txtR2);
            this.Controls.Add(this.lblR2);
            this.Controls.Add(this.lblV3);
            this.Controls.Add(this.txtV3);
            this.Controls.Add(this.txtR3);
            this.Controls.Add(this.lblR3);
            this.Controls.Add(this.lblV1);
            this.Controls.Add(this.txtV1);
            this.Controls.Add(this.txtR1);
            this.Controls.Add(this.lblR1);
            this.Controls.Add(this.txtVoltage);
            this.Controls.Add(this.chbxRemoveR3);
            this.Controls.Add(this.chbxRemoveTrackBar);
            this.Controls.Add(this.picCircuit1);
            this.Controls.Add(this.picCircuit2);
            this.Controls.Add(this.btnCalc);
            this.Controls.Add(this.tbrVoltage);
            this.Name = "Form1";
            this.Text = "Resistance, Voltage, Current";
            ((System.ComponentModel.ISupportInitialize)(this.tbrVoltage)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.picCircuit2)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.picCircuit1)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TrackBar tbrVoltage;
        private System.Windows.Forms.Button btnCalc;
        private System.Windows.Forms.PictureBox picCircuit2;
        private System.Windows.Forms.PictureBox picCircuit1;
        private System.Windows.Forms.CheckBox chbxRemoveTrackBar;
        private System.Windows.Forms.CheckBox chbxRemoveR3;
        private System.Windows.Forms.TextBox txtVoltage;
        private System.Windows.Forms.Label lblR1;
        private System.Windows.Forms.TextBox txtR1;
        private System.Windows.Forms.TextBox txtV1;
        private System.Windows.Forms.Label lblV1;
        private System.Windows.Forms.Label lblV3;
        private System.Windows.Forms.TextBox txtV3;
        private System.Windows.Forms.TextBox txtR3;
        private System.Windows.Forms.Label lblR3;
        private System.Windows.Forms.Label lblV2;
        private System.Windows.Forms.TextBox txtV2;
        private System.Windows.Forms.TextBox txtR2;
        private System.Windows.Forms.Label lblR2;
        private System.Windows.Forms.Label lblI;
        private System.Windows.Forms.TextBox txtI;
        private System.Windows.Forms.TextBox txtIDirection;
        private System.Windows.Forms.Label lblPower;
        private System.Windows.Forms.Label lblWatts;
        private System.Windows.Forms.TextBox txtPower;
        private System.Windows.Forms.TextBox txtI2;
        private System.Windows.Forms.Label lblI2;
        private System.Windows.Forms.Label label1;
    }
}

