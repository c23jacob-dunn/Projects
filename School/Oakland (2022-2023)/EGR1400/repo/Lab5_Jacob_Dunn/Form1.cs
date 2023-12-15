/* ‘LAB 5
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
• ‘Plagiarizing from work of others. Plagiarism is using someone else's work or ideas without
‘giving the other person credit; by doing this, a student is, in effect, claiming credit for
‘someone else's thinking. Whether the student has read or heard the information he/she
uses, ‘the student must document the source of information. When dealing with written
sources, ‘a clear distinction would be made between quotations (which reproduce
information from ‘the source word-for-word within quotation marks) and paraphrases (which
digest the ‘source information and produce it in the student's own words). Both direct
quotations and ‘paraphrases must be documented. Just because a student rephrases,
condenses or selects ‘from another person's work, the ideas are still the other person's, and
failure to give ‘credit constitutes misrepresentation of the student's actual work and
plagiarism of ‘another's ideas. Naturally, buying a paper and handing it in as one's own work
is ‘plagiarism.
• ‘Cheating on lab reports falsifying data or submitting data not based on student's own work.
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

namespace Lab5_Jacob_Dunn
{
    public partial class Form1 : Form
    {
        float voltage = 4;
        public Form1()
        {
            InitializeComponent();
        }

        private void btnCalc_Click(object sender, EventArgs e)
        {
            float desiredPower = float.Parse(txtPower.Text);
            float p2 = 0;

            for (double v = 0; p2 < desiredPower; v += .1)
            {
                voltage = (float)v;
                txtVoltage.Text = voltage.ToString("");

                float r1, r2, r3;
                float.TryParse(txtR1.Text, out r1);
                float.TryParse(txtR2.Text, out r2);
                float.TryParse(txtR3.Text, out r3);
                float v1 = (r1 / (r1 + r2)) * voltage;
                float v2 = (r2 / (r1 + r2)) * voltage;
                txtV1.Text = v1.ToString("0.##");
                txtV2.Text = v2.ToString("0.##");
                float v3 = voltage;
                float r12 = r1 + r2;
                float r123;
                float current;

                float current2 = v2 / r2;
                txtI2.Text = current2.ToString("0.####");

                if (picCircuit1.Visible == true)
                {
                    r123 = (r3 * r12) / (r3 + r12);
                    current = voltage / r123;
                    txtI.Text = current.ToString("0.####");
                    txtV3.Text = v3.ToString("");
                }
                else if (picCircuit2.Visible == true)
                {
                    current = voltage / r12;
                    txtI.Text = current.ToString("0.####");
                }

                p2 = current2 * v2;
            }
        }

    
        private void chbxRemoveR3_CheckedChanged(object sender, EventArgs e)
        {
            if(picCircuit1.Visible == true)
            {
                picCircuit1.Visible = false;
                picCircuit2.Visible = true;
                txtR3.Visible = false;
                lblR3.Visible = false;
                txtV3.Visible = false;
                lblV3.Visible = false;
            }

            else if (picCircuit2.Visible == true)
            {
                picCircuit1.Visible = true;
                picCircuit2.Visible = false;
                txtR3.Visible = true;
                lblR3.Visible = true;
                txtV3.Visible = true;
                lblV3.Visible = true;
            }
        }

        private void tbrVoltage_Scroll(object sender, EventArgs e)
        {
            voltage = tbrVoltage.Value;
            txtVoltage.Text = voltage.ToString("");

            float r1, r2, r3;
            float.TryParse(txtR1.Text, out r1);
            float.TryParse(txtR2.Text, out r2);
            float.TryParse(txtR3.Text, out r3);
            float v1 = (r1 / (r1 + r2)) * voltage;
            float v2 = (r2 / (r1 + r2)) * voltage;
            txtV1.Text = v1.ToString("0.##");
            txtV2.Text = v2.ToString("0.##");
            float v3 = voltage;
            float r12 = r1 + r2;
            float r123;
            float current;

            float current2 = v2 / r2;
            txtI2.Text = current2.ToString("0.####");

            if (picCircuit1.Visible == true)
            {
                r123 = (r3 * r12) / (r3 + r12);
                current = voltage / r123;
                txtI.Text = current.ToString("0.####");
                txtV3.Text = v3.ToString("");
            }
            else if (picCircuit2.Visible == true)
            {
                current = voltage / r12;
                txtI.Text = current.ToString("0.####");
            }
        }

        private void txtR1_TextChanged(object sender, EventArgs e)
        {
            float r1, r2, r3;
            float.TryParse(txtR1.Text, out r1);
            float.TryParse(txtR2.Text, out r2);
            float.TryParse(txtR3.Text, out r3);
            float v1 = (r1 / (r1 + r2)) * voltage;
            float v2 = (r2 / (r1 + r2)) * voltage;
            txtV1.Text = v1.ToString("0.##");
            txtV2.Text = v2.ToString("0.##");
            float v3 = voltage;
            float r12 = r1 + r2;
            float r123;
            float current;

            float current2 = v2 / r2;
            txtI2.Text = current2.ToString("0.####");

            if (picCircuit1.Visible == true)
            {
                r123 = (r3 * r12) / (r3 + r12);
                current = voltage / r123;
                txtI.Text = current.ToString("0.####");
                txtV3.Text = v3.ToString("");
            }
            else if (picCircuit2.Visible == true)
            {
                current = voltage / r12;
                txtI.Text = current.ToString("0.####");
            }
        }

        private void txtR3_TextChanged(object sender, EventArgs e)
        {
            float r1, r2, r3;
            float.TryParse(txtR1.Text, out r1);
            float.TryParse(txtR2.Text, out r2);
            float.TryParse(txtR3.Text, out r3);
            float v1 = (r1 / (r1 + r2)) * voltage;
            float v2 = (r2 / (r1 + r2)) * voltage;
            txtV1.Text = v1.ToString("0.##");
            txtV2.Text = v2.ToString("0.##");
            float v3 = voltage;
            float r12 = r1 + r2;
            float r123;
            float current;

            float current2 = v2 / r2;
            txtI2.Text = current2.ToString("0.####");

            if (picCircuit1.Visible == true)
            {
                r123 = (r3 * r12) / (r3 + r12);
                current = voltage / r123;
                txtI.Text = current.ToString("0.####");
                txtV3.Text = v3.ToString("");
            }
            else if (picCircuit2.Visible == true)
            {
                current = voltage / r12;
                txtI.Text = current.ToString("0.####");
            }
        }

        private void txtR2_TextChanged(object sender, EventArgs e)
        {
            float r1, r2, r3;
            float.TryParse(txtR1.Text, out r1);
            float.TryParse(txtR2.Text, out r2);
            float.TryParse(txtR3.Text, out r3);
            float v1 = (r1 / (r1 + r2)) * voltage;
            float v2 = (r2 / (r1 + r2)) * voltage;
            txtV1.Text = v1.ToString("0.##");
            txtV2.Text = v2.ToString("0.##");
            float v3 = voltage;
            float r12 = r1 + r2;
            float r123;
            float current;

            float current2 = v2 / r2;
            txtI2.Text = current2.ToString("0.####");

            if (picCircuit1.Visible == true)
            {
                r123 = (r3 * r12) / (r3 + r12);
                current = voltage / r123;
                txtI.Text = current.ToString("0.####");
                txtV3.Text = v3.ToString("");
            }
            else if (picCircuit2.Visible == true)
            {
                current = voltage / r12;
                txtI.Text = current.ToString("0.####");
            }
        }

        private void chbxRemoveTrackBar_CheckedChanged(object sender, EventArgs e)
        {
            if (tbrVoltage.Visible == true)
            {
                tbrVoltage.Visible = false;
                txtVoltage.Text = "?";
                chbxRemoveR3.Visible = false;
                txtPower.Visible = true;
                lblPower.Visible = true;
                lblWatts.Visible = true;
                lblI2.Visible = true;
                txtI2.Visible = true;
            }

            else if (tbrVoltage.Visible == false)
            {
                tbrVoltage.Visible = true;
                txtVoltage.Text = voltage.ToString();
                chbxRemoveR3.Visible = true;
                txtPower.Visible = false;
                lblPower.Visible = false;
                lblWatts.Visible = false;
                lblI2.Visible = false;
                txtI2.Visible = false;
            }
        }
    }
}
