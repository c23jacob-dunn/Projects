using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Windows.Forms.DataVisualization.Charting;
using static System.Windows.Forms.VisualStyles.VisualStyleElement.Rebar;

namespace PS04_Caden_Jacob
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            rdoNUniform.Checked = true;
        }
        public int GetRandomUniform(int min, int max)
        {
            Random rand = new Random();
            int num = rand.Next(min, max + 1);
            return num;
        }
        public double GetRandomNormal(double mean, double stddev)
        {
            // Box-Muller Transformation
            Random rand = new Random();
            double r = rand.NextDouble();
            double phi = rand.NextDouble();
            double z = (Math.Cos(2 * Math.PI * r)) * (Math.Sqrt(-2 * Math.Log(phi)));
            // z is normal with mean = 0 and stddev = 1.
            // We use our values of mean and stddev to 
            // scale z, giving us x.
            return z * stddev + mean;
        }
        public int GetBinIndex(double mini, double maxi, int numbins, double valuetobin)
        {
            //
            double b = ((valuetobin - mini) *((double)numbins / (maxi - mini)));
            int binIndex = (int)Math.Ceiling(b);
            return binIndex;
            //valuetobin is Pt to be assigned to a bin
            //mini is Ptmin
            //maxi is Ptmax
            //numbins is number of bins
        }

        private void btnCalculate_Click(object sender, EventArgs e)
        {
            double numIterations = double.Parse(txtIterations.Text);
            int numBins = (int)double.Parse(txtBins.Text);
            
            if(rdoPvNormal.Checked == true && rdoNUniform.Checked == true)
            {
                double nMin = double.Parse(txtNMin.Text);
                double nMax = double.Parse(txtNMax.Text);
                double pvMean = double.Parse(txtPvMean.Text);
                double pvStdev = double.Parse(txtPvStdev.Text);

                double pvMin = pvMean - (3 * pvStdev);
                double pvMax = pvMean + (3 * pvStdev);

                double ptMin = nMin * pvMin;
                double ptMax = nMax * pvMax;

                int[] binsArray = new int[numBins + 2];
                double totalProfit = 0;

                double range = ptMax - ptMin;
                double increment = range / numBins;

                for (int i = 0; i < numIterations; i++)
                {
                    double n = GetRandomUniform((int)nMin, (int)nMax);
                    double pv = GetRandomNormal(pvMean, pvStdev);

                    double pt = n * pv;

                    int binIndex = GetBinIndex(ptMin, ptMax, numBins, pt) - 1;

                    binsArray[binIndex + 1]++;
                    totalProfit += pt;


                    chrProfit.Series["Profit"].Points.Clear();
                    for (int j = 1; j < numBins + 1; j++)
                    {
                        chrProfit.Series["Profit"].Points.AddXY(ptMin + (increment * j), binsArray[j]);
                    }
                }
                
                totalProfit /= numIterations;
                txtTotalProfit.Text = "$" + totalProfit.ToString("N2");
            }

            if (rdoNNormal.Checked == true && rdoPvUniform.Checked == true)
            {
                double nMean = double.Parse(txtNMean.Text);
                double nStdev = double.Parse(txtNStdev.Text);
                double pvMin1 = double.Parse(txtPvMin.Text);
                double pvMax1 = double.Parse(txtPvMax.Text);

                double nMin = nMean - (3 * nStdev);
                double nMax = nMean + (3 * nStdev);

                double ptMin = pvMin1 * nMin;
                double ptMax = pvMax1 * nMax;

                int[] binsArray = new int[numBins + 2];
                double totalProfit = 0;

                double range = ptMax - ptMin;
                double increment = range / numBins;

                for (int i = 0; i < numIterations; i++)
                {
                    double n = GetRandomNormal(nMean, nStdev);
                    double pv = GetRandomUniform((int)pvMin1, (int)pvMax1);

                    double pt = n * pv;

                    int binIndex = GetBinIndex(ptMin, ptMax, numBins, pt) - 1;

                    binsArray[binIndex + 1]++;
                    totalProfit += pt;


                    chrProfit.Series["Profit"].Points.Clear();
                    for (int j = 1; j < numBins + 1; j++)
                    {
                        chrProfit.Series["Profit"].Points.AddXY(ptMin + (increment * j), binsArray[j]);
                    }
                }

                totalProfit /= numIterations;
                txtTotalProfit.Text = "$" + totalProfit.ToString("N2");
            }
        }

        private void rdoPvUniform_CheckedChanged(object sender, EventArgs e)
        {
            if (rdoPvNormal.Checked == true)
            {
                txtPvMean.Visible = true;
                lblPvMean.Visible = true;
                txtPvStdev.Visible = true;
                lblPvStdev.Visible = true;
                txtPvMin.Visible = false;
                lblPvMin.Visible = false;
                txtPvMax.Visible = false;
                lblPvMax.Visible = false;
            }
            else if (rdoPvUniform.Checked == true)
            {
                txtPvMean.Visible = false;
                lblPvMean.Visible = false;
                txtPvStdev.Visible = false;
                lblPvStdev.Visible = false;
                txtPvMin.Visible = true;
                lblPvMin.Visible = true;
                txtPvMax.Visible = true;
                lblPvMax.Visible = true;
            }
        }

        private void rdoNUniform_CheckedChanged(object sender, EventArgs e)
        {
            if (rdoNNormal.Checked == true)
            {
                txtNMean.Visible = true;
                lblNMean.Visible = true;
                txtNStdev.Visible = true;
                lblNStdev.Visible = true;
                txtNMin.Visible = false;
                lblNMin.Visible = false;
                txtNMax.Visible = false;
                lblNMax.Visible = false;
            }
            else if (rdoNUniform.Checked == true)
            {
                txtNMean.Visible = false;
                lblNMean.Visible = false;
                txtNStdev.Visible = false;
                lblNStdev.Visible = false;
                txtNMin.Visible = true;
                lblNMin.Visible = true;
                txtNMax.Visible = true;
                lblNMax.Visible = true;
            }
        }
    }
}
