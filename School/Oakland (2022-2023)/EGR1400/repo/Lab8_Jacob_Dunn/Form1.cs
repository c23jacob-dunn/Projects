/* ‘LAB 8
‘Fall 2022 EGR 1400
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
• ‘Plagiarizing from work of others. Plagiarism is using someone else's work or ideas without
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
• ‘Cheating on lab reports falsifying data or submitting data not based on student's own work.
*/

using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Xml.Linq;
using static System.Windows.Forms.AxHost;

namespace Lab8_Jacob_Dunn
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        class Global
        {
            public static double bilirubinDiedSum, bilirubinDiedSum2, bilirubinLivedSum, bilirubinLivedSum2, bilirubinDiedAverage, bilirubinDiedStdev, bilirubinLivedAverage, bilirubinLivedStdev;
            public static int bilirubinDiedRecordCount, bilirubinLivedRecordCount;

            public static double alkPhosphateDiedSum, alkPhosphateDiedSum2, alkPhosphateLivedSum, alkPhosphateLivedSum2, alkPhosphateDiedAverage, alkPhosphateDiedStdev, alkPhosphateLivedAverage, alkPhosphateLivedStdev;
            public static int alkPhosphateDiedRecordCount, alkPhosphateLivedRecordCount;

            public static double sGotDiedSum, sGotDiedSum2, sGotLivedSum, sGotLivedSum2, sGotDiedAverage, sGotDiedStdev, sGotLivedAverage, sGotLivedStdev;
            public static int sGotDiedRecordCount, sGotLivedRecordCount;

            public static double albuminDiedSum, albuminDiedSum2, albuminLivedSum, albuminLivedSum2, albuminDiedAverage, albuminDiedStdev, albuminLivedAverage, albuminLivedStdev;
            public static int albuminDiedRecordCount, albuminLivedRecordCount;
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            // TODO: This line of code loads data into the 'medicalRecords1400DataSet.MedicalRecords' table. You can move, or remove it, as needed.
            this.medicalRecordsTableAdapter.Fill(this.medicalRecords1400DataSet.MedicalRecords);
        }

        private void btnAnalyze_Click(object sender, EventArgs e)
        {
            XElement hospital = XElement.Load(@"C:\Users\Jacob\Documents\Fall 2022\EGR1400\Lab Handouts\LAB8\BloodTests.xml");

            var bloodTests = from testResult in hospital.Descendants("BloodTests")
                             let patientID = testResult.Element("PatientID").Value
                             let bilirubin = testResult.Element("Bilirubin").Value
                             let alkPhosphate = testResult.Element("AlkPhosphate").Value
                             let sGot = testResult.Element("SGot").Value
                             let albumin = testResult.Element("Albumin").Value
                             select new { patientID, bilirubin, alkPhosphate, sGot, albumin };

            foreach (var testResult in bloodTests)
            {
                if(double.Parse(testResult.bilirubin) != -99)
                {
                    var patients = from patient in medicalRecords1400DataSet.MedicalRecords
                                let ID = patient.PatientID
                                select new { patient.Alive };
                    foreach(var patient in patients)
                    {
                        if(patient.Alive == 1)
                        {
                            Global.bilirubinDiedSum += double.Parse(testResult.bilirubin);
                            Global.bilirubinDiedSum2 += Math.Pow(double.Parse(testResult.bilirubin), 2);
                            Global.bilirubinDiedRecordCount += 1;
                        }
                        else
                        {
                            Global.bilirubinLivedSum += double.Parse(testResult.bilirubin);
                            Global.bilirubinLivedSum2 += Math.Pow(double.Parse(testResult.bilirubin), 2);
                            Global.bilirubinLivedRecordCount += 1;
                        }
                    }
                }
            }

            Global.bilirubinDiedAverage = Global.bilirubinDiedSum / Global.bilirubinDiedRecordCount;
            Global.bilirubinDiedStdev = Math.Pow((Global.bilirubinDiedSum2 / Global.bilirubinDiedRecordCount) - (Math.Pow(Global.bilirubinDiedAverage, 2)), 1/2);

            Global.bilirubinLivedAverage = Global.bilirubinLivedSum / Global.bilirubinLivedRecordCount;
            Global.bilirubinLivedStdev = Math.Pow((Global.bilirubinLivedSum2 / Global.bilirubinLivedRecordCount) - Math.Pow(Global.bilirubinLivedAverage, 2), 1/2);

            lstDisplay.Items.Add("Average Bilrubin (Lived): " + Global.bilirubinLivedAverage.ToString("0.##"));
            lstDisplay.Items.Add("Stdev Bilrubin (Lived): " + Global.bilirubinLivedStdev.ToString("0.##"));
            lstDisplay.Items.Add("Average Bilrubin (Died): " + Global.bilirubinDiedAverage.ToString("0.##"));
            lstDisplay.Items.Add("Stdev Bilrubin (Died): " + Global.bilirubinDiedStdev.ToString("0.##"));


            foreach (var testResult in bloodTests)
            {
                if (double.Parse(testResult.alkPhosphate) != -99)
                {
                    var patients = from patient in medicalRecords1400DataSet.MedicalRecords
                                   let ID = patient.PatientID
                                   select new { patient.Alive };
                    foreach (var patient in patients)
                    {
                        if (patient.Alive == 1)
                        {
                            Global.alkPhosphateDiedSum += double.Parse(testResult.alkPhosphate);
                            Global.alkPhosphateDiedSum2 += Math.Pow(double.Parse(testResult.alkPhosphate), 2);
                            Global.alkPhosphateDiedRecordCount += 1;
                        }
                        else
                        {
                            Global.alkPhosphateLivedSum += double.Parse(testResult.alkPhosphate);
                            Global.alkPhosphateLivedSum2 += Math.Pow(double.Parse(testResult.alkPhosphate), 2);
                            Global.alkPhosphateLivedRecordCount += 1;
                        }
                    }
                }
            }

            Global.alkPhosphateDiedAverage = Global.alkPhosphateDiedSum / Global.alkPhosphateDiedRecordCount;
            Global.alkPhosphateDiedStdev = Math.Pow( ((Global.alkPhosphateDiedSum2 / Global.alkPhosphateDiedRecordCount) - Math.Pow(Global.bilirubinDiedAverage, 2)), 1/2);

            Global.alkPhosphateLivedAverage = Global.alkPhosphateLivedSum / Global.alkPhosphateLivedRecordCount;
            Global.alkPhosphateLivedStdev = Math.Pow((Global.alkPhosphateLivedSum2 / Global.alkPhosphateLivedRecordCount) - Math.Pow(Global.alkPhosphateLivedAverage, 2), 1 / 2);

            lstDisplay.Items.Add("Average AlkPhosphate (Lived): " + Global.alkPhosphateLivedAverage.ToString("0.##"));
            lstDisplay.Items.Add("Stdev AlkPhosphate (Lived): " + Global.alkPhosphateLivedStdev.ToString("0.##"));
            lstDisplay.Items.Add("Average AlkPhosphate (Died): " + Global.alkPhosphateDiedAverage.ToString("0.##"));
            lstDisplay.Items.Add("Stdev AlkPhosphate (Died): " + Global.alkPhosphateDiedStdev.ToString("0.##"));


            foreach (var testResult in bloodTests)
            {
                if (double.Parse(testResult.sGot) != -99)
                {
                    var patients = from patient in medicalRecords1400DataSet.MedicalRecords
                                   let ID = patient.PatientID
                                   select new { patient.Alive };
                    foreach (var patient in patients)
                    {
                        if (patient.Alive == 1)
                        {
                            Global.sGotDiedSum += double.Parse(testResult.sGot);
                            Global.sGotDiedSum2 += Math.Pow(double.Parse(testResult.sGot), 2);
                            Global.sGotDiedRecordCount += 1;
                        }
                        else
                        {
                            Global.sGotLivedSum += double.Parse(testResult.sGot);
                            Global.sGotLivedSum2 += Math.Pow(double.Parse(testResult.sGot), 2);
                            Global.sGotLivedRecordCount += 1;
                        }
                    }
                }
            }

            Global.sGotDiedAverage = Global.sGotDiedSum / Global.sGotDiedRecordCount;
            Global.sGotDiedStdev = Math.Pow((Global.sGotDiedSum2 / Global.sGotDiedRecordCount) - Math.Pow(Global.sGotDiedAverage, 2), 1 / 2);

            Global.sGotLivedAverage = Global.sGotLivedSum / Global.sGotLivedRecordCount;
            Global.sGotLivedStdev = Math.Pow((Global.sGotLivedSum2 / Global.sGotLivedRecordCount) - Math.Pow(Global.sGotLivedAverage, 2), 1 / 2);

            lstDisplay.Items.Add("Average SGot (Lived): " + Global.sGotLivedAverage.ToString("0.##"));
            lstDisplay.Items.Add("Stdev SGot (Lived): " + Global.sGotLivedStdev.ToString("0.##"));
            lstDisplay.Items.Add("Average SGot (Died): " + Global.sGotDiedAverage.ToString("0.##"));
            lstDisplay.Items.Add("Stdev SGot (Died): " + Global.sGotDiedStdev.ToString("0.##"));


            foreach (var testResult in bloodTests)
            {
                if (double.Parse(testResult.albumin) != -99)
                {
                    var patients = from patient in medicalRecords1400DataSet.MedicalRecords
                                   let ID = patient.PatientID
                                   select new { patient.Alive };
                    foreach (var patient in patients)
                    {
                        if (patient.Alive == 1)
                        {
                            Global.albuminDiedSum += double.Parse(testResult.albumin);
                            Global.albuminDiedSum2 += Math.Pow(double.Parse(testResult.albumin), 2);
                            Global.albuminDiedRecordCount += 1;
                        }
                        else
                        {
                            Global.albuminLivedSum += double.Parse(testResult.albumin);
                            Global.albuminLivedSum2 += Math.Pow(double.Parse(testResult.albumin), 2);
                            Global.albuminLivedRecordCount += 1;
                        }
                    }
                }
            }

            Global.albuminDiedAverage = Global.albuminDiedSum / Global.albuminDiedRecordCount;
            Global.albuminDiedStdev = Math.Pow((Global.albuminDiedSum2 / Global.albuminDiedRecordCount) - Math.Pow(Global.albuminDiedAverage, 2), 1 / 2);

            Global.albuminLivedAverage = Global.albuminLivedSum / Global.albuminLivedRecordCount;
            Global.albuminLivedStdev = Math.Pow((Global.albuminLivedSum2 / Global.albuminLivedRecordCount) - Math.Pow(Global.albuminLivedAverage, 2), 1 / 2);

            lstDisplay.Items.Add("Average Albumin (Lived): " + Global.albuminLivedAverage.ToString("0.##"));
            lstDisplay.Items.Add("Stdev Albumin (Lived): " + Global.albuminLivedStdev.ToString("0.##"));
            lstDisplay.Items.Add("Average Albumin (Died): " + Global.albuminDiedAverage.ToString("0.##"));
            lstDisplay.Items.Add("Stdev Albumin (Died): " + Global.albuminDiedStdev.ToString("0.##"));
        }
    }
}
