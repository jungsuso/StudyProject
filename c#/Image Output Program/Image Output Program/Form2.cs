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
    public partial class Form2 : Form
    {
        Image Original_image; // 변환을 위해 기본 이미지 복사
        bool status = true; // 그레이 변환 < - > 컬러 변환
        string file_extension;

        public Form2(string image_file)
        {
            InitializeComponent();

            pictureBox1.Image = Bitmap.FromFile(image_file);

            Original_image = pictureBox1.Image.Clone() as Bitmap;

            file_extension = image_file.Substring(image_file.IndexOf('.'), 4);
        }

        private Bitmap CopyImage()
        {
            pictureBox1.Image.Dispose();
            pictureBox1.Image = Original_image.Clone() as Image;
            Bitmap copy_image = pictureBox1.Image as Bitmap;

            return copy_image;
        }

        

        // Change Color
        private void button1_Click(object sender, EventArgs e)
        {
            if (status == true)
            {
                Bitmap tmp = CopyImage();

                Color colorData;

                for (int i = 0; i < tmp.Width; ++i)
                {
                    for (int j = 0; j < tmp.Height; ++j)
                    {
                        colorData = tmp.GetPixel(i, j);
                        GrayConvert(ref colorData);
                        tmp.SetPixel(i, j, colorData);
                    }
                }
                status = false;
            }
            else if (status == false)
            {
                pictureBox1.Image.Dispose();
                pictureBox1.Image = Original_image.Clone() as Image;
                status = true;
            }
        }

        private void GrayConvert(ref Color colorData)
        {
            int res = (colorData.R + colorData.G + colorData.B) / 3;
            colorData = Color.FromArgb(res, res, res); // 3개의 값의 평균으로 색상을 조정
            // RGB간의 색상의 격차가 없으면 없을수록 색감은 무채색을 띈다.
        }

        // Info
        private void button2_Click(object sender, EventArgs e)
        {
            Form3 infoForm = new Form3(file_extension);
            infoForm.ShowDialog();
        }

        // Quit
        private void button3_Click(object sender, EventArgs e)
        {
            Close();
        }
    }
}
