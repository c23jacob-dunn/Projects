/*‘LAB 6
‘EGR 1400 Fall 2022
‘Jacob Dunn
‘I fully understand the following statement.
‘OU PLAGIARISM POLICY
‘All members of the academic community at Oakland are expected to practice and uphold ‘standards
of academic integrity and honesty. An instructor is expected to inform and instruct ‘students about
the procedures and standards of research and documentation required of students ‘in fulfilling
course work. A student is expected to follow such instructions and be sure the rules ‘and procedures
are understood in order to avoid inadvertent misrepresentation of her/his work. ‘Students must
assume that individual (unaided) work on exams and lab reports and documentation ‘of sources is
expected unless the instructor specifically says that is not necessary.
‘The following definitions are some examples of academic dishonesty:
 ‘Plagiarizing from work of others. Plagiarism is using someone else's work or ideas without
‘giving the other person credit; by doing this, a student is, in effect, claiming credit for
‘someone else's thinking. Whether the student has read or heard the information she/he
uses, ‘the student must document the source of information. When dealing with written
sources, ‘a clear distinction would be made between quotations (which reproduce
information from ‘the source word-for-word within quotation marks) and paraphrases (which
digest the ‘source information and produce it in the student's own words). Both direct
quotations and ‘paraphrases must be documented. Just because a student rephrases,
condenses or selects ‘from another person's work, the ideas are still the other person's, and
failure to give ‘credit constitutes misrepresentation of the student's actual work and
plagiarism of ‘another's ideas. Naturally, buying a paper and handing it in as one's own work
is ‘plagiarism.
 ‘Cheating on lab reports falsifying data or submitting data not based on student's own work.
*/

using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Drawing.Text;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Windows.Forms.DataVisualization.Charting;

namespace Lab6_Jacob_Dunn
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        class Global
        {
            public static double a, b, c, xmin, xmax, ymin, ymax, numPoints;
        }

        private void tabCtrlWindow_SelectedIndexChanged(Object sender, EventArgs e)
        {
            switch (tabCtrlWindow.SelectedIndex)
            {
                case 0:
                    break;
                case 1:
                    break;
                case 2:
                    Window_Parameters();
                    Graph_Data();
                    break;
                default:
                    break;
            }
        }

        private void Window_Parameters()
        {
            Global.a = double.Parse(txtA.Text);
            Global.b = double.Parse(txtB.Text);
            Global.c = double.Parse(txtC.Text);

            Global.xmin = double.Parse(txtXmin.Text);
            Global.xmax = double.Parse(txtXmax.Text);
            Global.ymin = double.Parse(txtYmin.Text);
            Global.ymax = double.Parse(txtYmax.Text);
            Global.numPoints = double.Parse(txtNumPoints.Text);
            chart1.ChartAreas[0].Axes[0].Minimum = Global.xmin;
            chart1.ChartAreas[0].Axes[0].Maximum = Global.xmax;
            chart1.ChartAreas[0].Axes[1].Minimum = Global.ymin;
            chart1.ChartAreas[0].Axes[1].Maximum = Global.ymax;
        }

        private void Graph_Data()
        {
            txtEquation.Text = "y = " + Global.a + "x^2 + " + Global.b + "x + " + Global.c;
            
            for (double i = Global.xmin; i < Global.numPoints; i+=(Global.xmax - Global.xmin)/Global.numPoints)
            {
                double x = i;
                double y = Global.a*Math.Pow(x,2) + Global.b*x + Global.c;
                chart1.Series["Parabola"].Points.AddXY(x, y);
            }
        }
    }
}
