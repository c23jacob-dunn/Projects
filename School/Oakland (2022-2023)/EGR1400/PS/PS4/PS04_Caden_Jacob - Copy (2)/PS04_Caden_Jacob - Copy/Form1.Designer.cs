namespace PS04_Caden_Jacob
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
            System.Windows.Forms.DataVisualization.Charting.ChartArea chartArea5 = new System.Windows.Forms.DataVisualization.Charting.ChartArea();
            System.Windows.Forms.DataVisualization.Charting.Legend legend5 = new System.Windows.Forms.DataVisualization.Charting.Legend();
            System.Windows.Forms.DataVisualization.Charting.Series series5 = new System.Windows.Forms.DataVisualization.Charting.Series();
            System.Windows.Forms.DataVisualization.Charting.Title title5 = new System.Windows.Forms.DataVisualization.Charting.Title();
            this.txtTotalProfit = new System.Windows.Forms.TextBox();
            this.lblIterations = new System.Windows.Forms.Label();
            this.chrProfit = new System.Windows.Forms.DataVisualization.Charting.Chart();
            this.txtPvStdev = new System.Windows.Forms.TextBox();
            this.txtPvMean = new System.Windows.Forms.TextBox();
            this.txtBins = new System.Windows.Forms.TextBox();
            this.txtNMax = new System.Windows.Forms.TextBox();
            this.txtNMin = new System.Windows.Forms.TextBox();
            this.txtIterations = new System.Windows.Forms.TextBox();
            this.lblNMin = new System.Windows.Forms.Label();
            this.lblNMax = new System.Windows.Forms.Label();
            this.lblBins = new System.Windows.Forms.Label();
            this.lblPvMean = new System.Windows.Forms.Label();
            this.lblPvStdev = new System.Windows.Forms.Label();
            this.lblTotalProfit = new System.Windows.Forms.Label();
            this.btnCalculate = new System.Windows.Forms.Button();
            this.rdoPvUniform = new System.Windows.Forms.RadioButton();
            this.rdoPvNormal = new System.Windows.Forms.RadioButton();
            this.lblPvMax = new System.Windows.Forms.Label();
            this.lblPvMin = new System.Windows.Forms.Label();
            this.txtPvMax = new System.Windows.Forms.TextBox();
            this.txtPvMin = new System.Windows.Forms.TextBox();
            this.lblNStdev = new System.Windows.Forms.Label();
            this.txtNStdev = new System.Windows.Forms.TextBox();
            this.lblNMean = new System.Windows.Forms.Label();
            this.txtNMean = new System.Windows.Forms.TextBox();
            this.grpPv = new System.Windows.Forms.GroupBox();
            this.grpN = new System.Windows.Forms.GroupBox();
            this.rdoNNormal = new System.Windows.Forms.RadioButton();
            this.rdoNUniform = new System.Windows.Forms.RadioButton();
            ((System.ComponentModel.ISupportInitialize)(this.chrProfit)).BeginInit();
            this.grpPv.SuspendLayout();
            this.grpN.SuspendLayout();
            this.SuspendLayout();
            // 
            // txtTotalProfit
            // 
            this.txtTotalProfit.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.txtTotalProfit.Location = new System.Drawing.Point(772, 111);
            this.txtTotalProfit.Margin = new System.Windows.Forms.Padding(2);
            this.txtTotalProfit.Name = "txtTotalProfit";
            this.txtTotalProfit.ReadOnly = true;
            this.txtTotalProfit.Size = new System.Drawing.Size(114, 35);
            this.txtTotalProfit.TabIndex = 0;
            // 
            // lblIterations
            // 
            this.lblIterations.AutoSize = true;
            this.lblIterations.Location = new System.Drawing.Point(373, 438);
            this.lblIterations.Margin = new System.Windows.Forms.Padding(2, 0, 2, 0);
            this.lblIterations.Name = "lblIterations";
            this.lblIterations.Size = new System.Drawing.Size(50, 13);
            this.lblIterations.TabIndex = 1;
            this.lblIterations.Text = "Iterations";
            // 
            // chrProfit
            // 
            chartArea5.Name = "ChartArea1";
            this.chrProfit.ChartAreas.Add(chartArea5);
            legend5.Name = "Legend1";
            this.chrProfit.Legends.Add(legend5);
            this.chrProfit.Location = new System.Drawing.Point(28, 22);
            this.chrProfit.Margin = new System.Windows.Forms.Padding(2);
            this.chrProfit.Name = "chrProfit";
            series5.ChartArea = "ChartArea1";
            series5.Legend = "Legend1";
            series5.Name = "Profit";
            this.chrProfit.Series.Add(series5);
            this.chrProfit.Size = new System.Drawing.Size(683, 376);
            this.chrProfit.TabIndex = 2;
            this.chrProfit.Text = "chart1";
            title5.Name = "Title";
            title5.Text = "Distribution of Bins";
            this.chrProfit.Titles.Add(title5);
            // 
            // txtPvStdev
            // 
            this.txtPvStdev.Location = new System.Drawing.Point(229, 172);
            this.txtPvStdev.Margin = new System.Windows.Forms.Padding(2);
            this.txtPvStdev.Name = "txtPvStdev";
            this.txtPvStdev.Size = new System.Drawing.Size(76, 20);
            this.txtPvStdev.TabIndex = 3;
            // 
            // txtPvMean
            // 
            this.txtPvMean.Location = new System.Drawing.Point(229, 132);
            this.txtPvMean.Margin = new System.Windows.Forms.Padding(2);
            this.txtPvMean.Name = "txtPvMean";
            this.txtPvMean.Size = new System.Drawing.Size(76, 20);
            this.txtPvMean.TabIndex = 4;
            // 
            // txtBins
            // 
            this.txtBins.Location = new System.Drawing.Point(213, 438);
            this.txtBins.Margin = new System.Windows.Forms.Padding(2);
            this.txtBins.Name = "txtBins";
            this.txtBins.Size = new System.Drawing.Size(76, 20);
            this.txtBins.TabIndex = 5;
            // 
            // txtNMax
            // 
            this.txtNMax.Location = new System.Drawing.Point(247, 83);
            this.txtNMax.Margin = new System.Windows.Forms.Padding(2);
            this.txtNMax.Name = "txtNMax";
            this.txtNMax.Size = new System.Drawing.Size(76, 20);
            this.txtNMax.TabIndex = 6;
            // 
            // txtNMin
            // 
            this.txtNMin.Location = new System.Drawing.Point(247, 40);
            this.txtNMin.Margin = new System.Windows.Forms.Padding(2);
            this.txtNMin.Name = "txtNMin";
            this.txtNMin.Size = new System.Drawing.Size(76, 20);
            this.txtNMin.TabIndex = 7;
            // 
            // txtIterations
            // 
            this.txtIterations.Location = new System.Drawing.Point(427, 438);
            this.txtIterations.Margin = new System.Windows.Forms.Padding(2);
            this.txtIterations.Name = "txtIterations";
            this.txtIterations.Size = new System.Drawing.Size(76, 20);
            this.txtIterations.TabIndex = 8;
            // 
            // lblNMin
            // 
            this.lblNMin.AutoSize = true;
            this.lblNMin.Location = new System.Drawing.Point(193, 40);
            this.lblNMin.Margin = new System.Windows.Forms.Padding(2, 0, 2, 0);
            this.lblNMin.Name = "lblNMin";
            this.lblNMin.Size = new System.Drawing.Size(30, 13);
            this.lblNMin.TabIndex = 9;
            this.lblNMin.Text = "nMin";
            // 
            // lblNMax
            // 
            this.lblNMax.AutoSize = true;
            this.lblNMax.Location = new System.Drawing.Point(193, 83);
            this.lblNMax.Margin = new System.Windows.Forms.Padding(2, 0, 2, 0);
            this.lblNMax.Name = "lblNMax";
            this.lblNMax.Size = new System.Drawing.Size(33, 13);
            this.lblNMax.TabIndex = 10;
            this.lblNMax.Text = "nMax";
            // 
            // lblBins
            // 
            this.lblBins.AutoSize = true;
            this.lblBins.Location = new System.Drawing.Point(159, 438);
            this.lblBins.Margin = new System.Windows.Forms.Padding(2, 0, 2, 0);
            this.lblBins.Name = "lblBins";
            this.lblBins.Size = new System.Drawing.Size(27, 13);
            this.lblBins.TabIndex = 11;
            this.lblBins.Text = "Bins";
            // 
            // lblPvMean
            // 
            this.lblPvMean.AutoSize = true;
            this.lblPvMean.Location = new System.Drawing.Point(175, 132);
            this.lblPvMean.Margin = new System.Windows.Forms.Padding(2, 0, 2, 0);
            this.lblPvMean.Name = "lblPvMean";
            this.lblPvMean.Size = new System.Drawing.Size(50, 13);
            this.lblPvMean.TabIndex = 12;
            this.lblPvMean.Text = "Pv-Mean";
            // 
            // lblPvStdev
            // 
            this.lblPvStdev.AutoSize = true;
            this.lblPvStdev.Location = new System.Drawing.Point(175, 175);
            this.lblPvStdev.Margin = new System.Windows.Forms.Padding(2, 0, 2, 0);
            this.lblPvStdev.Name = "lblPvStdev";
            this.lblPvStdev.Size = new System.Drawing.Size(51, 13);
            this.lblPvStdev.TabIndex = 13;
            this.lblPvStdev.Text = "Pv-Stdev";
            // 
            // lblTotalProfit
            // 
            this.lblTotalProfit.AutoSize = true;
            this.lblTotalProfit.Font = new System.Drawing.Font("Microsoft Sans Serif", 14F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblTotalProfit.Location = new System.Drawing.Point(754, 64);
            this.lblTotalProfit.Margin = new System.Windows.Forms.Padding(2, 0, 2, 0);
            this.lblTotalProfit.Name = "lblTotalProfit";
            this.lblTotalProfit.Size = new System.Drawing.Size(152, 32);
            this.lblTotalProfit.TabIndex = 14;
            this.lblTotalProfit.Text = "Total Profit";
            // 
            // btnCalculate
            // 
            this.btnCalculate.Location = new System.Drawing.Point(760, 286);
            this.btnCalculate.Margin = new System.Windows.Forms.Padding(2);
            this.btnCalculate.Name = "btnCalculate";
            this.btnCalculate.Size = new System.Drawing.Size(153, 112);
            this.btnCalculate.TabIndex = 15;
            this.btnCalculate.Text = "Calculate";
            this.btnCalculate.UseVisualStyleBackColor = true;
            this.btnCalculate.Click += new System.EventHandler(this.btnCalculate_Click);
            // 
            // rdoPvUniform
            // 
            this.rdoPvUniform.AutoSize = true;
            this.rdoPvUniform.Location = new System.Drawing.Point(18, 86);
            this.rdoPvUniform.Margin = new System.Windows.Forms.Padding(2);
            this.rdoPvUniform.Name = "rdoPvUniform";
            this.rdoPvUniform.Size = new System.Drawing.Size(123, 20);
            this.rdoPvUniform.TabIndex = 16;
            this.rdoPvUniform.Text = "Uniform Distribution";
            this.rdoPvUniform.UseVisualStyleBackColor = true;
            this.rdoPvUniform.CheckedChanged += new System.EventHandler(this.rdoPvUniform_CheckedChanged);
            // 
            // rdoPvNormal
            // 
            this.rdoPvNormal.AutoSize = true;
            this.rdoPvNormal.Checked = true;
            this.rdoPvNormal.Location = new System.Drawing.Point(18, 126);
            this.rdoPvNormal.Margin = new System.Windows.Forms.Padding(2);
            this.rdoPvNormal.Name = "rdoPvNormal";
            this.rdoPvNormal.Size = new System.Drawing.Size(120, 20);
            this.rdoPvNormal.TabIndex = 17;
            this.rdoPvNormal.TabStop = true;
            this.rdoPvNormal.Text = "Normal Distribution";
            this.rdoPvNormal.UseVisualStyleBackColor = true;
            // 
            // lblPvMax
            // 
            this.lblPvMax.AutoSize = true;
            this.lblPvMax.Location = new System.Drawing.Point(179, 91);
            this.lblPvMax.Margin = new System.Windows.Forms.Padding(2, 0, 2, 0);
            this.lblPvMax.Name = "lblPvMax";
            this.lblPvMax.Size = new System.Drawing.Size(43, 13);
            this.lblPvMax.TabIndex = 18;
            this.lblPvMax.Text = "Pv-Max";
            this.lblPvMax.Visible = false;
            // 
            // lblPvMin
            // 
            this.lblPvMin.AutoSize = true;
            this.lblPvMin.Location = new System.Drawing.Point(179, 50);
            this.lblPvMin.Margin = new System.Windows.Forms.Padding(2, 0, 2, 0);
            this.lblPvMin.Name = "lblPvMin";
            this.lblPvMin.Size = new System.Drawing.Size(40, 13);
            this.lblPvMin.TabIndex = 19;
            this.lblPvMin.Text = "Pv-Min";
            this.lblPvMin.Visible = false;
            // 
            // txtPvMax
            // 
            this.txtPvMax.Location = new System.Drawing.Point(229, 88);
            this.txtPvMax.Margin = new System.Windows.Forms.Padding(2);
            this.txtPvMax.Name = "txtPvMax";
            this.txtPvMax.Size = new System.Drawing.Size(76, 20);
            this.txtPvMax.TabIndex = 20;
            this.txtPvMax.Visible = false;
            // 
            // txtPvMin
            // 
            this.txtPvMin.Location = new System.Drawing.Point(229, 47);
            this.txtPvMin.Margin = new System.Windows.Forms.Padding(2);
            this.txtPvMin.Name = "txtPvMin";
            this.txtPvMin.Size = new System.Drawing.Size(76, 20);
            this.txtPvMin.TabIndex = 21;
            this.txtPvMin.Visible = false;
            // 
            // lblNStdev
            // 
            this.lblNStdev.AutoSize = true;
            this.lblNStdev.Location = new System.Drawing.Point(193, 178);
            this.lblNStdev.Margin = new System.Windows.Forms.Padding(2, 0, 2, 0);
            this.lblNStdev.Name = "lblNStdev";
            this.lblNStdev.Size = new System.Drawing.Size(50, 13);
            this.lblNStdev.TabIndex = 22;
            this.lblNStdev.Text = "n-Stddev";
            // 
            // txtNStdev
            // 
            this.txtNStdev.Location = new System.Drawing.Point(247, 175);
            this.txtNStdev.Margin = new System.Windows.Forms.Padding(2);
            this.txtNStdev.Name = "txtNStdev";
            this.txtNStdev.Size = new System.Drawing.Size(76, 20);
            this.txtNStdev.TabIndex = 23;
            // 
            // lblNMean
            // 
            this.lblNMean.AutoSize = true;
            this.lblNMean.Location = new System.Drawing.Point(193, 133);
            this.lblNMean.Name = "lblNMean";
            this.lblNMean.Size = new System.Drawing.Size(44, 13);
            this.lblNMean.TabIndex = 24;
            this.lblNMean.Text = "N-mean";
            // 
            // txtNMean
            // 
            this.txtNMean.Location = new System.Drawing.Point(247, 133);
            this.txtNMean.Margin = new System.Windows.Forms.Padding(2);
            this.txtNMean.Name = "txtNMean";
            this.txtNMean.Size = new System.Drawing.Size(76, 20);
            this.txtNMean.TabIndex = 25;
            // 
            // grpPv
            // 
            this.grpPv.Controls.Add(this.txtPvMin);
            this.grpPv.Controls.Add(this.txtPvStdev);
            this.grpPv.Controls.Add(this.txtPvMean);
            this.grpPv.Controls.Add(this.lblPvMean);
            this.grpPv.Controls.Add(this.lblPvStdev);
            this.grpPv.Controls.Add(this.rdoPvUniform);
            this.grpPv.Controls.Add(this.txtPvMax);
            this.grpPv.Controls.Add(this.rdoPvNormal);
            this.grpPv.Controls.Add(this.lblPvMin);
            this.grpPv.Controls.Add(this.lblPvMax);
            this.grpPv.Location = new System.Drawing.Point(100, 493);
            this.grpPv.Name = "grpPv";
            this.grpPv.Size = new System.Drawing.Size(346, 235);
            this.grpPv.TabIndex = 26;
            this.grpPv.TabStop = false;
            this.grpPv.Text = "Pv";
            // 
            // grpN
            // 
            this.grpN.Controls.Add(this.rdoNNormal);
            this.grpN.Controls.Add(this.rdoNUniform);
            this.grpN.Controls.Add(this.txtNMin);
            this.grpN.Controls.Add(this.txtNMax);
            this.grpN.Controls.Add(this.txtNMean);
            this.grpN.Controls.Add(this.lblNMin);
            this.grpN.Controls.Add(this.lblNMean);
            this.grpN.Controls.Add(this.lblNMax);
            this.grpN.Controls.Add(this.txtNStdev);
            this.grpN.Controls.Add(this.lblNStdev);
            this.grpN.Location = new System.Drawing.Point(507, 493);
            this.grpN.Name = "grpN";
            this.grpN.Size = new System.Drawing.Size(346, 235);
            this.grpN.TabIndex = 27;
            this.grpN.TabStop = false;
            this.grpN.Text = "N";
            // 
            // rdoNNormal
            // 
            this.rdoNNormal.AutoSize = true;
            this.rdoNNormal.Location = new System.Drawing.Point(19, 125);
            this.rdoNNormal.Name = "rdoNNormal";
            this.rdoNNormal.Size = new System.Drawing.Size(120, 20);
            this.rdoNNormal.TabIndex = 27;
            this.rdoNNormal.TabStop = true;
            this.rdoNNormal.Text = "Normal Distribution";
            this.rdoNNormal.UseVisualStyleBackColor = true;
            // 
            // rdoNUniform
            // 
            this.rdoNUniform.AutoSize = true;
            this.rdoNUniform.Location = new System.Drawing.Point(19, 91);
            this.rdoNUniform.Name = "rdoNUniform";
            this.rdoNUniform.Size = new System.Drawing.Size(123, 20);
            this.rdoNUniform.TabIndex = 26;
            this.rdoNUniform.TabStop = true;
            this.rdoNUniform.Text = "Uniform Distribution";
            this.rdoNUniform.UseVisualStyleBackColor = true;
            this.rdoNUniform.CheckedChanged += new System.EventHandler(this.rdoNUniform_CheckedChanged);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(946, 781);
            this.Controls.Add(this.grpN);
            this.Controls.Add(this.grpPv);
            this.Controls.Add(this.btnCalculate);
            this.Controls.Add(this.lblTotalProfit);
            this.Controls.Add(this.lblBins);
            this.Controls.Add(this.txtIterations);
            this.Controls.Add(this.txtBins);
            this.Controls.Add(this.chrProfit);
            this.Controls.Add(this.lblIterations);
            this.Controls.Add(this.txtTotalProfit);
            this.Margin = new System.Windows.Forms.Padding(2);
            this.Name = "Form1";
            this.Text = "Simulation";
            ((System.ComponentModel.ISupportInitialize)(this.chrProfit)).EndInit();
            this.grpPv.ResumeLayout(false);
            this.grpPv.PerformLayout();
            this.grpN.ResumeLayout(false);
            this.grpN.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TextBox txtTotalProfit;
        private System.Windows.Forms.Label lblIterations;
        private System.Windows.Forms.DataVisualization.Charting.Chart chrProfit;
        private System.Windows.Forms.TextBox txtPvStdev;
        private System.Windows.Forms.TextBox txtPvMean;
        private System.Windows.Forms.TextBox txtBins;
        private System.Windows.Forms.TextBox txtNMax;
        private System.Windows.Forms.TextBox txtNMin;
        private System.Windows.Forms.TextBox txtIterations;
        private System.Windows.Forms.Label lblNMin;
        private System.Windows.Forms.Label lblNMax;
        private System.Windows.Forms.Label lblBins;
        private System.Windows.Forms.Label lblPvMean;
        private System.Windows.Forms.Label lblPvStdev;
        private System.Windows.Forms.Label lblTotalProfit;
        private System.Windows.Forms.Button btnCalculate;
        private System.Windows.Forms.RadioButton rdoPvUniform;
        private System.Windows.Forms.RadioButton rdoPvNormal;
        private System.Windows.Forms.Label lblPvMax;
        private System.Windows.Forms.Label lblPvMin;
        private System.Windows.Forms.TextBox txtPvMax;
        private System.Windows.Forms.TextBox txtPvMin;
        private System.Windows.Forms.Label lblNStdev;
        private System.Windows.Forms.TextBox txtNStdev;
        private System.Windows.Forms.Label lblNMean;
        private System.Windows.Forms.TextBox txtNMean;
        private System.Windows.Forms.GroupBox grpPv;
        private System.Windows.Forms.GroupBox grpN;
        private System.Windows.Forms.RadioButton rdoNNormal;
        private System.Windows.Forms.RadioButton rdoNUniform;
    }
}

