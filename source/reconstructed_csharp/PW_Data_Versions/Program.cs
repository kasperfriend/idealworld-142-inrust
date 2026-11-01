using System;
using System.Windows.Forms;

namespace PW_Data_Versions
{
    internal static class Program
    {
        [STAThread]
        private static void Main()
        {
            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);
            Application.Run(new main());
        }
    }
}
