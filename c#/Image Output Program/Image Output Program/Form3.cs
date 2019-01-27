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
    public partial class Form3 : Form
    {
        public Form3(string file_extension)
        {
            InitializeComponent();

            switch (file_extension)
            {
                case ".bmp":
                    pictureBox1.Load(@"C:\Users\inyon\source\repos\Image Output Program\Image Output Program\Image\BMP_info.jpg");
                    break;
                case ".jp2":
                    pictureBox1.Load(@"C:\Users\inyon\source\repos\Image Output Program\Image Output Program\Image\JP2_info.jpg");
                    break;
                case ".jpg":
                    pictureBox1.Load(@"C:\Users\inyon\source\repos\Image Output Program\Image Output Program\Image\JPEG_info.jpg");
                    break;
                case ".png":
                    pictureBox1.Load(@"C:\Users\inyon\source\repos\Image Output Program\Image Output Program\Image\PNG_info.jpg");
                    break;
                case ".tif":
                    pictureBox1.Load(@"C:\Users\inyon\source\repos\Image Output Program\Image Output Program\Image\TIFF_info.jpg");
                    break;
            }
        }

        // Quit
        private void button1_Click(object sender, EventArgs e)
        {
            Close();
        }
    }
}
