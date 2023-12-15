/* ‘LAB 4
‘Fall 2022
‘Jacob Dunn
‘I fully understand the following statement.
‘OU PLAGIARISM POLICY
‘All members of the academic community at Oakland are expected to practice and uphold ‘standards
of academic integrity and honesty. An instructor is expected to inform and instruct ‘students about
the procedures and standards of research and documentation required of students ‘in fulfilling
course work. A student is expected to follow such instructions and be sure the rules ‘and procedures
are understood in order to avoid inadvertent misrepresentation of his work. ‘Students must assume
that individual (unaided) work on exams and lab reports and documentation ‘of sources is expected
unless the instructor specifically says that is not necessary.
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
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Reflection;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using static System.Windows.Forms.VisualStyles.VisualStyleElement;
using static System.Windows.Forms.VisualStyles.VisualStyleElement.ToolTip;

namespace Lab4_Jacob_Dunn
{
    public partial class Form1 : Form
    {
        int state = 1;
        int point = 0;
        int status = 0;
        int score = 0;
        public Form1()
        {
            InitializeComponent();
        }

        private void btnRoll_Click(object sender, EventArgs e)
        {
            pic11.Visible = false;
            pic12.Visible = false;
            pic13.Visible = false;
            pic14.Visible = false;
            pic15.Visible = false;
            pic16.Visible = false;
            pic21.Visible = false;
            pic22.Visible = false;
            pic23.Visible = false;
            pic24.Visible = false;
            pic25.Visible = false;
            pic26.Visible = false;

            Random rand = new Random();
            int die1 = rand.Next(1, 7);
            int die2 = rand.Next(1, 7);
            int total = die1 + die2;

            txtDie1.Text = die1.ToString();
            txtDie2.Text = die2.ToString();
            txtTotal.Text = total.ToString();

            switch (die1)
            {
                case 1:
                    pic11.Visible = true;
                    pic12.Visible = false;
                    pic13.Visible = false;
                    pic14.Visible = false;
                    pic15.Visible = false;
                    pic16.Visible = false;
                    break;

                case 2:
                    pic11.Visible = false;
                    pic12.Visible = true;
                    pic13.Visible = false;
                    pic14.Visible = false;
                    pic15.Visible = false;
                    pic16.Visible = false;
                    break;

                case 3:
                    pic11.Visible = false;
                    pic12.Visible = false;
                    pic13.Visible = true;
                    pic14.Visible = false;
                    pic15.Visible = false;
                    pic16.Visible = false;
                    break;

                case 4:
                    pic11.Visible = false;
                    pic12.Visible = false;
                    pic13.Visible = false;
                    pic14.Visible = true;
                    pic15.Visible = false;
                    pic16.Visible = false;
                    break;

                case 5:
                    pic11.Visible = false;
                    pic12.Visible = false;
                    pic13.Visible = false;
                    pic14.Visible = false;
                    pic15.Visible = true;
                    pic16.Visible = false;
                    break;

                case 6:
                    pic11.Visible = false;
                    pic12.Visible = false;
                    pic13.Visible = false;
                    pic14.Visible = false;
                    pic15.Visible = false;
                    pic16.Visible = true;
                    break;

                default:
                    break;
            }

            switch (die2)
            {
                case 1:
                    pic21.Visible = true;
                    pic22.Visible = false;
                    pic23.Visible = false;
                    pic24.Visible = false;
                    pic25.Visible = false;
                    pic26.Visible = false;
                    break;

                case 2:
                    pic21.Visible = false;
                    pic22.Visible = true;
                    pic23.Visible = false;
                    pic24.Visible = false;
                    pic25.Visible = false;
                    pic26.Visible = false;
                    break;

                case 3:
                    pic21.Visible = false;
                    pic22.Visible = false;
                    pic23.Visible = true;
                    pic24.Visible = false;
                    pic25.Visible = false;
                    pic26.Visible = false;
                    break;

                case 4:
                    pic21.Visible = false;
                    pic22.Visible = false;
                    pic23.Visible = false;
                    pic24.Visible = true;
                    pic25.Visible = false;
                    pic26.Visible = false;
                    break;

                case 5:
                    pic21.Visible = false;
                    pic22.Visible = false;
                    pic23.Visible = false;
                    pic24.Visible = false;
                    pic25.Visible = true;
                    pic26.Visible = false;
                    break;

                case 6:
                    pic21.Visible = false;
                    pic22.Visible = false;
                    pic23.Visible = false;
                    pic24.Visible = false;
                    pic25.Visible = false;
                    pic26.Visible = true;
                    break;

                default:
                    break;
            }

            if (state == 1)
            {
                if (total == 7 || total == 11)
                {
                    status = 1;
                    score += 1;
                    state = 1;

                }
                else if (total == 2 || total == 3 || total == 12)
                {
                    status = -1;
                    score -= 1;
                    state = 1;
                }
                else
                {
                    status = 0;
                    state = 2;
                    point = total;
                    txtPoint.Text = point.ToString();

                    switch (point)
                    {
                        case 4:
                            picBPuck.Visible = false;
                            picWPuck4.Visible = true;
                            picWPuck5.Visible = false;
                            picWPuck6.Visible = false;
                            picWPuck8.Visible = false;
                            picWPuck9.Visible = false;
                            picWPuck10.Visible = false;
                            break;

                        case 5:
                            picBPuck.Visible = false;
                            picWPuck4.Visible = false;
                            picWPuck5.Visible = true;
                            picWPuck6.Visible = false;
                            picWPuck8.Visible = false;
                            picWPuck9.Visible = false;
                            picWPuck10.Visible = false;
                            break;

                        case 6:
                            picBPuck.Visible = false;
                            picWPuck4.Visible = false;
                            picWPuck5.Visible = false;
                            picWPuck6.Visible = true;
                            picWPuck8.Visible = false;
                            picWPuck9.Visible = false;
                            picWPuck10.Visible = false;
                            break;

                        case 8:
                            picBPuck.Visible = false;
                            picWPuck4.Visible = false;
                            picWPuck5.Visible = false;
                            picWPuck6.Visible = false;
                            picWPuck8.Visible = true;
                            picWPuck9.Visible = false;
                            picWPuck10.Visible = false;
                            break;

                        case 9:
                            picBPuck.Visible = false;
                            picWPuck4.Visible = false;
                            picWPuck5.Visible = false;
                            picWPuck6.Visible = false;
                            picWPuck8.Visible = false;
                            picWPuck9.Visible = true;
                            picWPuck10.Visible = false;
                            break;

                        case 10:
                            picBPuck.Visible = false;
                            picWPuck4.Visible = false;
                            picWPuck5.Visible = false;
                            picWPuck6.Visible = false;
                            picWPuck8.Visible = false;
                            picWPuck9.Visible = false;
                            picWPuck10.Visible = true;
                            break;

                        default:
                            picBPuck.Visible = false;
                            picWPuck4.Visible = false;
                            picWPuck5.Visible = false;
                            picWPuck6.Visible = false;
                            picWPuck8.Visible = false;
                            picWPuck9.Visible = false;
                            picWPuck10.Visible = false;
                            break;
                    }
                }
            }
            else
            {
                if(total == point)
                {
                    status = 1;
                    state = 1;
                    score += 1;
                }
                else if(total == 7)
                {
                    status = -1;
                    state = 1;
                    score -= 1;
                }
                else
                {
                    status = 0;
                    state = 2;
                }
            }

            if (status == 0)
            {
                txtOutput.Text = "The point is: " + point.ToString();
            }
            else if (status == 1)
            {
                txtOutput.Text = "You got the Point! \r\n Click roll for a new game.";
                picBPuck.Visible = true;
                picWPuck4.Visible = false;
                picWPuck5.Visible = false;
                picWPuck6.Visible = false;
                picWPuck8.Visible = false;
                picWPuck9.Visible = false;
                picWPuck10.Visible = false;
            }
            else if (status == -1)
            {
                txtOutput.Text = "You missed the Point! \r\n Click roll for a new game.";
                picBPuck.Visible = true;
                picWPuck4.Visible = false;
                picWPuck5.Visible = false;
                picWPuck6.Visible = false;
                picWPuck8.Visible = false;
                picWPuck9.Visible = false;
                picWPuck10.Visible = false;
            }

            txtScore.Text = score.ToString();
        }

        private void btnExit_Click(object sender, EventArgs e)
        {
            this.Close();
        }
    }
}
