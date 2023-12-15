/* LAB 3
‘EGR 1400 Fall 2022
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
‘someone else's thinking. Whether the student has read or heard the information he/she uses,
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
using System.Collections;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using static System.Windows.Forms.VisualStyles.VisualStyleElement;
using static System.Windows.Forms.VisualStyles.VisualStyleElement.Tab;

namespace Lab3_Jacob_Dunn
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            radUnder30.Checked = true;
        }

        private void btnExit_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void radMale_CheckedChanged(object sender, EventArgs e)
        {
            lblMForearm.Visible = true;
            lblMHips.Visible = true;
            lblMWaist.Visible = true;
            lblMWrist.Visible = true;

            lblFCalf.Visible = false;
            lblFHips.Visible = false;
            lblFThigh.Visible = false;
            lblFWrist.Visible = false;
        }

        private void btnCalculate_Click(object sender, EventArgs e)
        {
            double num1;
            if(double.TryParse(txtWeight.Text, out num1) &&
               double.TryParse(txtMeas1.Text, out num1) &&
               double.TryParse(txtMeas2.Text, out num1) &&
               double.TryParse(txtMeas3.Text, out num1) &&
               double.TryParse(txtMeas4.Text, out num1) )
            {
                if (radMale.Checked)
                {
                    double waist = double.Parse(txtMeas1.Text);
                    double hips = double.Parse(txtMeas2.Text);
                    double forearm = double.Parse(txtMeas3.Text);
                    double wrist = double.Parse(txtMeas4.Text);
                    double weight = double.Parse(txtWeight.Text);
                    double bodyFat, fat, lean, ideal;

                    if (radUnder30.Checked)
                    {
                        bodyFat = waist + (.5 * hips) - (3 * forearm) - wrist;
                        fat = weight * (bodyFat / 100);
                        lean = weight - fat;
                        ideal = lean / .85;
                        txtResults1.Text += "You have about " + lean.ToString("N0") + " lbs of lean body weight with " +
                                       fat.ToString("N0") + " lbs of fat (" + bodyFat.ToString("N0") + "%). \r\n" +
                                       "You should weigh no more than " + ideal.ToString("N0") + " lbs (15% fat).";
                    }
                    if (radOver30.Checked)
                    {
                        bodyFat = waist + (.5 * hips) - (2.7 * forearm) - wrist;
                        fat = weight * (bodyFat / 100);
                        lean = weight - fat;
                        ideal = lean / .85;
                        txtResults1.Text += "You have about " + lean.ToString("N0") + " lbs of lean body weight with " +
                                       fat.ToString("N0") + " lbs of fat (" + bodyFat.ToString("N0") + "%). \r\n" +
                                       "You should weigh no more than " + ideal.ToString("N0") + " lbs (15% fat).";
                    }
                }

                if (radFemale.Checked)
                {
                    double hips = double.Parse(txtMeas1.Text);
                    double thigh = double.Parse(txtMeas2.Text);
                    double calf = double.Parse(txtMeas3.Text);
                    double wrist = double.Parse(txtMeas4.Text);
                    double weight = double.Parse(txtWeight.Text);
                    double bodyFat, fat, lean, ideal;

                    if (radUnder30.Checked)
                    {
                        bodyFat = hips + (.8 * thigh) - (2 * calf) - wrist;
                        fat = weight * (bodyFat / 100);
                        lean = weight - fat;
                        ideal = lean / .78;
                        txtResults1.Text += "You have about " + lean.ToString("N0") + " lbs of lean body weight with " +
                                       fat.ToString("N0") + " lbs of fat (" + bodyFat.ToString("N0") + "%). \r\n" +
                                       "You should weigh no more than " + ideal.ToString("N0") + " lbs (22% fat).";
                    }
                    if (radFemale.Checked && radOver30.Checked)
                    {
                        bodyFat = hips + thigh - (2 * calf) - wrist;
                        fat = weight * (bodyFat / 100);
                        lean = weight - fat;
                        ideal = lean / .78;
                        txtResults1.Text += "You have about " + lean.ToString("N0") + " lbs of lean body weight with " +
                                       fat.ToString("N0") + " lbs of fat (" + bodyFat.ToString("N0") + "%). \r\n" +
                                       "You should weigh no more than " + ideal.ToString("N0") + " lbs (22% fat).";
                    }
                }    
            }

            else
            {
                MessageBox.Show("Missing a number!");
            }
        }

        private void radFemale_CheckedChanged(object sender, EventArgs e)
        {
            lblMForearm.Visible = false;
            lblMHips.Visible = false;
            lblMWaist.Visible = false;
            lblMWrist.Visible = false;

            lblFCalf.Visible = true;
            lblFHips.Visible = true;
            lblFThigh.Visible = true;
            lblFWrist.Visible = true;
        }

        private void btnReset_Click(object sender, EventArgs e)
        {
            txtWeight.Clear();
            txtMeas1.Clear();
            txtMeas2.Clear();
            txtMeas3.Clear();
            txtMeas4.Clear();
            txtResults1.Clear();
            radMale.Checked = true;
            radUnder30.Checked = true;
        }

        private void txtResults_TextChanged(object sender, EventArgs e)
        {

        }
    }
}
