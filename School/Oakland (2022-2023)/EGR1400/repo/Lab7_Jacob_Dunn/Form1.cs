﻿/*
LAB 7
Fall 2022 EGR1400
STUDENT’S Jacob Dunn
I fully understand the following statement.
OU PLAGIARISM POLICY
All members of the academic community at Oakland are expected to practice and uphold ‘standards
of academic integrity and honesty. An instructor is expected to inform and instruct ‘students about
the procedures and standards of research and documentation required of students ‘in fulfilling
course work. A student is expected to follow such instructions and be sure the rules ‘and procedures
are understood in order to avoid inadvertent misrepresentation of his work. ‘Students must assume
that individual (unaided) work on exams and lab reports and documentation ‘of sources is expected
unless the instructor specifically says that is not necessary.
The following definitions are some examples of academic dishonesty:
• Plagiarizing from work of others. Plagiarism is using someone else's work or ideas without
giving the other person credit; by doing this, a student is, in effect, claiming credit for
someone else's thinking. Whether the student has read or heard the information he uses, the
student must document the source of information. When dealing with written sources, a using System;
clear distinction would be made between quotations (which reproduce information from the
source word-for-word within quotation marks) and paraphrases (which digest the source
information and produce it in the student's own words). Both direct quotations and
paraphrases must be documented. Just because a student rephrases, condenses or selects
from another person's work, the ideas are still the other person's, and failure to give credit
constitutes misrepresentation of the student's actual work and plagiarism of another's ideas.
Naturally, buying a paper and handing it in as one's own work is plagiarism.
Cheating on lab reports falsifying data or submitting data not based on student's own work.
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
using System.IO;

namespace Lab7_Jacob_Dunn
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void btnList_Click(object sender, System.EventArgs e)
        {
            string dictData, palData;
            //int[] arrayDict = new int[26], arrayPal = new int[26];
            StreamReader dict = File.OpenText(@"C:\Users\jdunn\Documents\git\Projects\School\Oakland (2022-2023)\EGR1400\Lab Handouts\LAB7\dict.txt");
            if(dict == null)
            {
                lstAnagrams.Text = "Failed to open dict file";
            }
            
            while(!dict.EndOfStream)
            {
                dictData = dict.ReadLine();
                int[] arrayDict = new int[26];
                Histo.Histogram.CreateHistogram(arrayDict, dictData);

                StreamReader pal = File.OpenText(@"C:\Users\jdunn\Documents\git\Projects\School\Oakland (2022-2023)\EGR1400\Lab Handouts\LAB7\pal.txt");
                if (pal == null)
                {
                    lstAnagrams.Text = "Failed to open dict file";
                }

                while (!pal.EndOfStream)
                {
                    palData = pal.ReadLine();
                    int[] arrayPal = new int[26];
                    Histo.Histogram.CreateHistogram(arrayPal, palData);
                    int count = 0;

                    for(int i = 0; i < arrayPal.Length; i++)
                    {
                        if (arrayDict[i] == arrayPal[i])
                        {
                            count++;
                        }
                    }
                    
                    if(count == arrayPal.Length)
                    {
                        lstAnagrams.Items.Add(dictData + " --> " + palData);
                    }
                }
                pal.Close();
            }
            dict.Close();
        }
    }
}
