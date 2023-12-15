using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace RandomTxtBox
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            Random x = new Random();
            int num1;
            num1 = x.Next(1, 101);
            textBox1.Text = num1.ToString();
            //num2 = textBox1.Text.???
        }

        private void button2_Click(object sender, EventArgs e)
        {
            int num2;
            num2 = int.Parse(textBox1.Text);
            num2 = num2 * 2;
            textBox2.Text = num2.ToString();
        }
    }
}
