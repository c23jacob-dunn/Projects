namespace Lab6_Jacob_Dunn
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
            System.Windows.Forms.DataVisualization.Charting.ChartArea chartArea3 = new System.Windows.Forms.DataVisualization.Charting.ChartArea();
            System.Windows.Forms.DataVisualization.Charting.Legend legend3 = new System.Windows.Forms.DataVisualization.Charting.Legend();
            System.Windows.Forms.DataVisualization.Charting.Series series3 = new System.Windows.Forms.DataVisualization.Charting.Series();
            this.tabCtrlWindow = new System.Windows.Forms.TabControl();
            this.tabParameters = new System.Windows.Forms.TabPage();
            this.lblC = new System.Windows.Forms.Label();
            this.lblB = new System.Windows.Forms.Label();
            this.lblA = new System.Windows.Forms.Label();
            this.txtC = new System.Windows.Forms.TextBox();
            this.txtB = new System.Windows.Forms.TextBox();
            this.txtA = new System.Windows.Forms.TextBox();
            this.lblEquation = new System.Windows.Forms.Label();
            this.lblParabola = new System.Windows.Forms.Label();
            this.tabWindow = new System.Windows.Forms.TabPage();
            this.txtNumPoints = new System.Windows.Forms.TextBox();
            this.txtYmax = new System.Windows.Forms.TextBox();
            this.txtYmin = new System.Windows.Forms.TextBox();
            this.txtXmax = new System.Windows.Forms.TextBox();
            this.txtXmin = new System.Windows.Forms.TextBox();
            this.lblNumPoints = new System.Windows.Forms.Label();
            this.lblYmax = new System.Windows.Forms.Label();
            this.lblYmin = new System.Windows.Forms.Label();
            this.lblXmax = new System.Windows.Forms.Label();
            this.lblXmin = new System.Windows.Forms.Label();
            this.tabGraph = new System.Windows.Forms.TabPage();
            this.chart1 = new System.Windows.Forms.DataVisualization.Charting.Chart();
            this.txtEquation = new System.Windows.Forms.TextBox();
            this.tabCtrlWindow.SuspendLayout();
            this.tabParameters.SuspendLayout();
            this.tabWindow.SuspendLayout();
            this.tabGraph.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.chart1)).BeginInit();
            this.SuspendLayout();
            // 
            // tabCtrlWindow
            // 
            this.tabCtrlWindow.Controls.Add(this.tabParameters);
            this.tabCtrlWindow.Controls.Add(this.tabWindow);
            this.tabCtrlWindow.Controls.Add(this.tabGraph);
            this.tabCtrlWindow.Location = new System.Drawing.Point(12, 12);
            this.tabCtrlWindow.Name = "tabCtrlWindow";
            this.tabCtrlWindow.SelectedIndex = 0;
            this.tabCtrlWindow.Size = new System.Drawing.Size(1007, 647);
            this.tabCtrlWindow.TabIndex = 0;
            this.tabCtrlWindow.SelectedIndexChanged += new System.EventHandler(this.tabCtrlWindow_SelectedIndexChanged);
            // 
            // tabParameters
            // 
            this.tabParameters.Controls.Add(this.lblC);
            this.tabParameters.Controls.Add(this.lblB);
            this.tabParameters.Controls.Add(this.lblA);
            this.tabParameters.Controls.Add(this.txtC);
            this.tabParameters.Controls.Add(this.txtB);
            this.tabParameters.Controls.Add(this.txtA);
            this.tabParameters.Controls.Add(this.lblEquation);
            this.tabParameters.Controls.Add(this.lblParabola);
            this.tabParameters.Location = new System.Drawing.Point(4, 29);
            this.tabParameters.Name = "tabParameters";
            this.tabParameters.Padding = new System.Windows.Forms.Padding(3);
            this.tabParameters.Size = new System.Drawing.Size(999, 614);
            this.tabParameters.TabIndex = 0;
            this.tabParameters.Text = "Parameters";
            this.tabParameters.UseVisualStyleBackColor = true;
            // 
            // lblC
            // 
            this.lblC.AutoSize = true;
            this.lblC.Location = new System.Drawing.Point(409, 373);
            this.lblC.Name = "lblC";
            this.lblC.Size = new System.Drawing.Size(17, 20);
            this.lblC.TabIndex = 7;
            this.lblC.Text = "c";
            // 
            // lblB
            // 
            this.lblB.AutoSize = true;
            this.lblB.Location = new System.Drawing.Point(408, 314);
            this.lblB.Name = "lblB";
            this.lblB.Size = new System.Drawing.Size(18, 20);
            this.lblB.TabIndex = 6;
            this.lblB.Text = "b";
            // 
            // lblA
            // 
            this.lblA.AutoSize = true;
            this.lblA.Location = new System.Drawing.Point(408, 248);
            this.lblA.Name = "lblA";
            this.lblA.Size = new System.Drawing.Size(18, 20);
            this.lblA.TabIndex = 5;
            this.lblA.Text = "a";
            // 
            // txtC
            // 
            this.txtC.Location = new System.Drawing.Point(432, 370);
            this.txtC.Name = "txtC";
            this.txtC.Size = new System.Drawing.Size(100, 26);
            this.txtC.TabIndex = 4;
            // 
            // txtB
            // 
            this.txtB.Location = new System.Drawing.Point(432, 308);
            this.txtB.Name = "txtB";
            this.txtB.Size = new System.Drawing.Size(100, 26);
            this.txtB.TabIndex = 3;
            // 
            // txtA
            // 
            this.txtA.Location = new System.Drawing.Point(432, 245);
            this.txtA.Name = "txtA";
            this.txtA.Size = new System.Drawing.Size(100, 26);
            this.txtA.TabIndex = 2;
            // 
            // lblEquation
            // 
            this.lblEquation.AutoSize = true;
            this.lblEquation.Font = new System.Drawing.Font("Microsoft Sans Serif", 14F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblEquation.Location = new System.Drawing.Point(73, 153);
            this.lblEquation.Name = "lblEquation";
            this.lblEquation.Size = new System.Drawing.Size(221, 32);
            this.lblEquation.TabIndex = 1;
            this.lblEquation.Text = "y = ax^2 + bx + c";
            // 
            // lblParabola
            // 
            this.lblParabola.AutoSize = true;
            this.lblParabola.Font = new System.Drawing.Font("Microsoft Sans Serif", 26F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblParabola.Location = new System.Drawing.Point(69, 78);
            this.lblParabola.Name = "lblParabola";
            this.lblParabola.Size = new System.Drawing.Size(241, 59);
            this.lblParabola.TabIndex = 0;
            this.lblParabola.Text = "Parabola";
            // 
            // tabWindow
            // 
            this.tabWindow.Controls.Add(this.txtNumPoints);
            this.tabWindow.Controls.Add(this.txtYmax);
            this.tabWindow.Controls.Add(this.txtYmin);
            this.tabWindow.Controls.Add(this.txtXmax);
            this.tabWindow.Controls.Add(this.txtXmin);
            this.tabWindow.Controls.Add(this.lblNumPoints);
            this.tabWindow.Controls.Add(this.lblYmax);
            this.tabWindow.Controls.Add(this.lblYmin);
            this.tabWindow.Controls.Add(this.lblXmax);
            this.tabWindow.Controls.Add(this.lblXmin);
            this.tabWindow.Location = new System.Drawing.Point(4, 29);
            this.tabWindow.Name = "tabWindow";
            this.tabWindow.Padding = new System.Windows.Forms.Padding(3);
            this.tabWindow.Size = new System.Drawing.Size(999, 614);
            this.tabWindow.TabIndex = 1;
            this.tabWindow.Text = "Window";
            this.tabWindow.UseVisualStyleBackColor = true;
            // 
            // txtNumPoints
            // 
            this.txtNumPoints.Location = new System.Drawing.Point(466, 368);
            this.txtNumPoints.Name = "txtNumPoints";
            this.txtNumPoints.Size = new System.Drawing.Size(100, 26);
            this.txtNumPoints.TabIndex = 10;
            this.txtNumPoints.Text = "50";
            // 
            // txtYmax
            // 
            this.txtYmax.Location = new System.Drawing.Point(466, 311);
            this.txtYmax.Name = "txtYmax";
            this.txtYmax.Size = new System.Drawing.Size(100, 26);
            this.txtYmax.TabIndex = 9;
            this.txtYmax.Text = "10";
            // 
            // txtYmin
            // 
            this.txtYmin.Location = new System.Drawing.Point(466, 257);
            this.txtYmin.Name = "txtYmin";
            this.txtYmin.Size = new System.Drawing.Size(100, 26);
            this.txtYmin.TabIndex = 8;
            this.txtYmin.Text = "-10";
            // 
            // txtXmax
            // 
            this.txtXmax.Location = new System.Drawing.Point(466, 204);
            this.txtXmax.Name = "txtXmax";
            this.txtXmax.Size = new System.Drawing.Size(100, 26);
            this.txtXmax.TabIndex = 7;
            this.txtXmax.Text = "10";
            // 
            // txtXmin
            // 
            this.txtXmin.Location = new System.Drawing.Point(466, 149);
            this.txtXmin.Name = "txtXmin";
            this.txtXmin.Size = new System.Drawing.Size(100, 26);
            this.txtXmin.TabIndex = 6;
            this.txtXmin.Text = "-10";
            // 
            // lblNumPoints
            // 
            this.lblNumPoints.AutoSize = true;
            this.lblNumPoints.Location = new System.Drawing.Point(369, 371);
            this.lblNumPoints.Name = "lblNumPoints";
            this.lblNumPoints.Size = new System.Drawing.Size(66, 20);
            this.lblNumPoints.TabIndex = 5;
            this.lblNumPoints.Text = "# Points";
            // 
            // lblYmax
            // 
            this.lblYmax.AutoSize = true;
            this.lblYmax.Location = new System.Drawing.Point(390, 314);
            this.lblYmax.Name = "lblYmax";
            this.lblYmax.Size = new System.Drawing.Size(49, 20);
            this.lblYmax.TabIndex = 4;
            this.lblYmax.Text = "Ymax";
            // 
            // lblYmin
            // 
            this.lblYmin.AutoSize = true;
            this.lblYmin.Location = new System.Drawing.Point(390, 260);
            this.lblYmin.Name = "lblYmin";
            this.lblYmin.Size = new System.Drawing.Size(45, 20);
            this.lblYmin.TabIndex = 3;
            this.lblYmin.Text = "Ymin";
            // 
            // lblXmax
            // 
            this.lblXmax.AutoSize = true;
            this.lblXmax.Location = new System.Drawing.Point(390, 207);
            this.lblXmax.Name = "lblXmax";
            this.lblXmax.Size = new System.Drawing.Size(49, 20);
            this.lblXmax.TabIndex = 2;
            this.lblXmax.Text = "Xmax";
            // 
            // lblXmin
            // 
            this.lblXmin.AutoSize = true;
            this.lblXmin.Location = new System.Drawing.Point(390, 152);
            this.lblXmin.Name = "lblXmin";
            this.lblXmin.Size = new System.Drawing.Size(45, 20);
            this.lblXmin.TabIndex = 1;
            this.lblXmin.Text = "Xmin";
            // 
            // tabGraph
            // 
            this.tabGraph.Controls.Add(this.chart1);
            this.tabGraph.Controls.Add(this.txtEquation);
            this.tabGraph.Location = new System.Drawing.Point(4, 29);
            this.tabGraph.Name = "tabGraph";
            this.tabGraph.Padding = new System.Windows.Forms.Padding(3);
            this.tabGraph.Size = new System.Drawing.Size(999, 614);
            this.tabGraph.TabIndex = 2;
            this.tabGraph.Text = "Graph";
            this.tabGraph.UseVisualStyleBackColor = true;
            // 
            // chart1
            // 
            chartArea3.Name = "ChartArea1";
            this.chart1.ChartAreas.Add(chartArea3);
            legend3.Name = "Legend1";
            this.chart1.Legends.Add(legend3);
            this.chart1.Location = new System.Drawing.Point(109, 110);
            this.chart1.Name = "chart1";
            series3.ChartArea = "ChartArea1";
            series3.ChartType = System.Windows.Forms.DataVisualization.Charting.SeriesChartType.Spline;
            series3.Legend = "Legend1";
            series3.Name = "Parabola";
            this.chart1.Series.Add(series3);
            this.chart1.Size = new System.Drawing.Size(766, 427);
            this.chart1.TabIndex = 1;
            this.chart1.Text = "chart1";
            // 
            // txtEquation
            // 
            this.txtEquation.Location = new System.Drawing.Point(45, 44);
            this.txtEquation.Name = "txtEquation";
            this.txtEquation.ReadOnly = true;
            this.txtEquation.Size = new System.Drawing.Size(178, 26);
            this.txtEquation.TabIndex = 0;
            this.txtEquation.Text = "y = ";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(9F, 20F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1042, 673);
            this.Controls.Add(this.tabCtrlWindow);
            this.Name = "Form1";
            this.Text = "Graphing Calculator";
            this.tabCtrlWindow.ResumeLayout(false);
            this.tabParameters.ResumeLayout(false);
            this.tabParameters.PerformLayout();
            this.tabWindow.ResumeLayout(false);
            this.tabWindow.PerformLayout();
            this.tabGraph.ResumeLayout(false);
            this.tabGraph.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.chart1)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.TabControl tabCtrlWindow;
        private System.Windows.Forms.TabPage tabParameters;
        private System.Windows.Forms.TabPage tabWindow;
        private System.Windows.Forms.TabPage tabGraph;
        private System.Windows.Forms.Label lblC;
        private System.Windows.Forms.Label lblB;
        private System.Windows.Forms.Label lblA;
        private System.Windows.Forms.TextBox txtC;
        private System.Windows.Forms.TextBox txtB;
        private System.Windows.Forms.TextBox txtA;
        private System.Windows.Forms.Label lblEquation;
        private System.Windows.Forms.Label lblParabola;
        private System.Windows.Forms.TextBox txtNumPoints;
        private System.Windows.Forms.TextBox txtYmax;
        private System.Windows.Forms.TextBox txtYmin;
        private System.Windows.Forms.TextBox txtXmax;
        private System.Windows.Forms.TextBox txtXmin;
        private System.Windows.Forms.Label lblNumPoints;
        private System.Windows.Forms.Label lblYmax;
        private System.Windows.Forms.Label lblYmin;
        private System.Windows.Forms.Label lblXmax;
        private System.Windows.Forms.Label lblXmin;
        private System.Windows.Forms.TextBox txtEquation;
        private System.Windows.Forms.DataVisualization.Charting.Chart chart1;
    }
}

