namespace Lab1_Dunn
{
    partial class Lab1
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Lab1));
            this.picBoxOU = new System.Windows.Forms.PictureBox();
            this.lblTitle = new System.Windows.Forms.Label();
            this.btnDisplay = new System.Windows.Forms.Button();
            this.lblOutput = new System.Windows.Forms.Label();
            ((System.ComponentModel.ISupportInitialize)(this.picBoxOU)).BeginInit();
            this.SuspendLayout();
            // 
            // picBoxOU
            // 
            this.picBoxOU.Image = global::Lab1_Dunn.Properties.Resources.OUCampusMap;
            this.picBoxOU.Location = new System.Drawing.Point(183, 97);
            this.picBoxOU.Name = "picBoxOU";
            this.picBoxOU.Size = new System.Drawing.Size(627, 435);
            this.picBoxOU.SizeMode = System.Windows.Forms.PictureBoxSizeMode.Zoom;
            this.picBoxOU.TabIndex = 0;
            this.picBoxOU.TabStop = false;
            this.picBoxOU.Click += new System.EventHandler(this.pictureBox1_Click);
            // 
            // lblTitle
            // 
            this.lblTitle.AutoSize = true;
            this.lblTitle.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(255)))), ((int)(((byte)(128)))));
            this.lblTitle.Font = new System.Drawing.Font("Stencil", 16F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblTitle.Location = new System.Drawing.Point(35, 26);
            this.lblTitle.Name = "lblTitle";
            this.lblTitle.Size = new System.Drawing.Size(935, 38);
            this.lblTitle.TabIndex = 1;
            this.lblTitle.Text = "Directions to Oakland University Engineering Center";
            this.lblTitle.Click += new System.EventHandler(this.lblTitle_Click);
            // 
            // btnDisplay
            // 
            this.btnDisplay.BackColor = System.Drawing.SystemColors.ActiveCaption;
            this.btnDisplay.Location = new System.Drawing.Point(335, 579);
            this.btnDisplay.Name = "btnDisplay";
            this.btnDisplay.Size = new System.Drawing.Size(315, 46);
            this.btnDisplay.TabIndex = 2;
            this.btnDisplay.Text = "Directions to OU EC";
            this.btnDisplay.UseVisualStyleBackColor = false;
            this.btnDisplay.Click += new System.EventHandler(this.btnDisplay_Click);
            // 
            // lblOutput
            // 
            this.lblOutput.AutoSize = true;
            this.lblOutput.Location = new System.Drawing.Point(121, 658);
            this.lblOutput.Name = "lblOutput";
            this.lblOutput.Size = new System.Drawing.Size(773, 80);
            this.lblOutput.TabIndex = 3;
            this.lblOutput.Text = resources.GetString("lblOutput.Text");
            this.lblOutput.Visible = false;
            // 
            // Lab1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(9F, 20F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.SystemColors.Control;
            this.ClientSize = new System.Drawing.Size(1006, 852);
            this.Controls.Add(this.lblOutput);
            this.Controls.Add(this.btnDisplay);
            this.Controls.Add(this.lblTitle);
            this.Controls.Add(this.picBoxOU);
            this.Name = "Lab1";
            this.Text = "EGR 1400 LAB 1 DIRECTIONS TO OU EC";
            this.Load += new System.EventHandler(this.Form1_Load);
            ((System.ComponentModel.ISupportInitialize)(this.picBoxOU)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.PictureBox picBoxOU;
        private System.Windows.Forms.Label lblTitle;
        private System.Windows.Forms.Button btnDisplay;
        private System.Windows.Forms.Label lblOutput;
    }
}

