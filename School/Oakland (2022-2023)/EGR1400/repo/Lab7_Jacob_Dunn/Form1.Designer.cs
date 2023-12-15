namespace Lab7_Jacob_Dunn
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
            this.lstAnagrams = new System.Windows.Forms.ListBox();
            this.btnList = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // lstAnagrams
            // 
            this.lstAnagrams.FormattingEnabled = true;
            this.lstAnagrams.ItemHeight = 20;
            this.lstAnagrams.Location = new System.Drawing.Point(12, 12);
            this.lstAnagrams.Name = "lstAnagrams";
            this.lstAnagrams.Size = new System.Drawing.Size(703, 424);
            this.lstAnagrams.TabIndex = 0;
            // 
            // btnList
            // 
            this.btnList.Location = new System.Drawing.Point(12, 455);
            this.btnList.Name = "btnList";
            this.btnList.Size = new System.Drawing.Size(308, 92);
            this.btnList.TabIndex = 1;
            this.btnList.Text = "List the Anagrams";
            this.btnList.UseVisualStyleBackColor = true;
            this.btnList.Click += new System.EventHandler(this.btnList_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(9F, 20F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(743, 562);
            this.Controls.Add(this.btnList);
            this.Controls.Add(this.lstAnagrams);
            this.Name = "Form1";
            this.Text = "Anagrams";
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.ListBox lstAnagrams;
        private System.Windows.Forms.Button btnList;
    }
}

