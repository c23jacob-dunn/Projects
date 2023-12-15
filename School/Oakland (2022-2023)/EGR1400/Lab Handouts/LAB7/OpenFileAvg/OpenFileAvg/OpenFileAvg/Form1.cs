using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;

namespace OpenFileAvg
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            string data;
            int age, sum = 0, cnt = 0;
            double avg;
            StreamReader infile;
            infile = File.OpenText(@"C:\Users\siadat\Downloads\EGR1400\UsefulFiles\AgesAtInaugural.txt");

            //while (infile.EndOfStream == fale)
            while (!infile.EndOfStream)
            {
                data = infile.ReadLine();
                age = int.Parse(data);
                sum += age;
                cnt++;
            }
            avg = sum / (double)cnt;
            textBox1.Text = avg.ToString("n1");
            infile.Close();
        }
    }
}
