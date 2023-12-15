/*
‘LAB #2
‘EGR1400 Fall 2022
‘Jacob Dunn
‘I fully understand the following statement.
‘OU PLAGIARISM POLICY
‘All members of the academic community at Oakland are expected to practice and uphold ‘standards
of academic integrity and honesty. An instructor is expected to inform and instruct ‘students about
the procedures and standards of research and documentation required of students ‘in fulfilling
course work. A student is expected to follow such instructions and be sure the rules ‘and procedures
are understood in order to avoid inadvertent misrepresentation of his/her work. ‘Students must
assume that individual (unaided) work on exams and lab reports and documentation ‘of sources is
expected unless the instructor specifically says that is not necessary.
‘The following definitions are some examples of academic dishonesty:
 ‘Plagiarizing from work of others. Plagiarism is using someone else's work or ideas without
‘giving the other person credit; by doing this, a student is, in effect, claiming credit for
‘someone else's thinking. Whether the student has read or heard the information she/he uses,
‘the student must document the source of information. When dealing with written sources,
‘a clear distinction would be made between quotations (which reproduce information from
‘the source word-for-word within quotation marks) and paraphrases (which digest the
‘source information and produce it in the student's own words). Both direct quotations and
‘paraphrases must be documented. Just because a student rephrases, condenses or selects
‘from another person's work, the ideas are still the other person's, and failure to give ‘credit
constitutes misrepresentation of the student's actual work and plagiarism of ‘another's ideas.
Naturally, buying a paper and handing it in as one's own work is ‘plagiarism.
 ‘Cheating on lab reports falsifying data or submitting data not based on student's own work.
*/


using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using static System.Windows.Forms.VisualStyles.VisualStyleElement.Rebar;

namespace Lab2_Jacob_Dunn
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void btnRandom_Click(object sender, EventArgs e)
        {
            Random rand = new Random();
            int num1 = rand.Next(50, 101);
            textBox1.Text = num1.ToString();
            int num2 = rand.Next(50, 101);
            textBox2.Text = num2.ToString();
            int num3 = rand.Next(50, 101);
            textBox3.Text = num3.ToString();
            int num4 = rand.Next(50, 101);
            textBox4.Text = num4.ToString();
            int num5 = rand.Next(50, 101);
            textBox5.Text = num5.ToString();

            int num6 = rand.Next(30, 101);
            textBox6.Text = num6.ToString();
            int num7 = rand.Next(30, 101);
            textBox7.Text = num7.ToString();
            int num8 = rand.Next(30, 101);
            textBox8.Text = num8.ToString();
            int num9 = rand.Next(30, 101);
            textBox9.Text = num9.ToString();
            int num10 = rand.Next(30, 101);
            textBox10.Text = num10.ToString();
        }

        private void btnComputeStats_Click(object sender, EventArgs e)
        {
            double num1 = double.Parse(textBox1.Text);
            double num2 = double.Parse(textBox2.Text);
            double num3 = double.Parse(textBox3.Text);
            double num4 = double.Parse(textBox4.Text);
            double num5 = double.Parse(textBox5.Text);
            double num6 = double.Parse(textBox6.Text);
            double num7 = double.Parse(textBox7.Text);
            double num8 = double.Parse(textBox8.Text);
            double num9 = double.Parse(textBox9.Text);
            double num10 = double.Parse(textBox10.Text);

            double sum = num1 + num2 + num3 + num4 + num5 + 
                      num6 + num7 + num8 + num9 + num10;

            double mean = sum / 10;
            txtMean.Text = mean.ToString(".##");

            double sumOfSquares = ((Math.Pow(num1, 2)) + (Math.Pow(num2, 2)) +
                                  (Math.Pow(num3, 2)) + (Math.Pow(num4, 2)) +
                                  (Math.Pow(num5, 2)) + (Math.Pow(num6, 2)) +
                                  (Math.Pow(num7, 2)) + (Math.Pow(num8, 2)) +
                                  (Math.Pow(num9, 2)) + (Math.Pow(num10, 2)) );

            double stdDev = Math.Sqrt( (sumOfSquares / 10) - (Math.Pow(mean, 2)) );
            txtStdDev.Text = stdDev.ToString(".##");

        }

        private void btnClear_Click(object sender, EventArgs e)
        {
            textBox1.Clear();
            textBox2.Clear();
            textBox3.Clear();
            textBox4.Clear();
            textBox5.Clear();
            textBox6.Clear();
            textBox7.Clear();
            textBox8.Clear();
            textBox9.Clear();
            textBox10.Clear();

            txtMean.Clear();
            txtStdDev.Clear();
        }

        private void btnExit_Click(object sender, EventArgs e)
        {
            this.Close();
        }
    }
}
