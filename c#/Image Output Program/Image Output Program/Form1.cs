using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Image_Output_Program
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        // Select Image
        private void button1_Click(object sender, EventArgs e)
        {
            OpenFileDialog openFile = new OpenFileDialog();
            openFile.InitialDirectory = @"C:\Users\inyon\source\repos\Image Output Program\Image Output Program\Image";
            openFile.Filter = "Image File (*.jpg, *.bmp, *.png, *.jp2, *.tif)|*.jpg; *.bmp;  *.png;  *.jp2;  *.tif|All files(*.*)|*.*";

            if(openFile.ShowDialog() == DialogResult.OK)
            {
                string image_file = string.Empty;
                image_file = openFile.FileName;
                Form2 pictureForm = new Form2(image_file);
                pictureForm.Location = new Point(this.Location.X, this.Location.Y);
                pictureForm.Owner = this;
                pictureForm.ShowDialog();
            }

            else if(openFile.ShowDialog() == DialogResult.Cancel)
            {
                return;
            }
        }

        // Quit
        private void button2_Click(object sender, EventArgs e)
        {
            Close();
        }
               
    }
}
