using System;
using System.IO;
using System.Windows.Forms;

namespace PW_Data_Versions
{
    // Exact CIL-verified reconstruction of PW_Data_Versions.exe (15 MethodDefs, RVAs 8272..10952)
    public partial class main : Form
    {
        private string curDir;

        public main()
        {
            this.InitializeComponent();
            string currentDirectory = Environment.CurrentDirectory;
            if (File.Exists(currentDirectory + "\\elements.data"))
            {
                this.curDir = currentDirectory;
                this.popList(this.curDir);
            }
        }

        private string timestamp_to_string(int timestamp)
        {
            DateTime dt = new DateTime(1970, 1, 1, 0, 0, 0, 0);
            dt = dt.AddSeconds((double)timestamp);
            return dt.ToString("yyyy-MM-dd HH:mm:ss");
        }

        private void popList(string dir)
        {
            this.lblDir.Text = dir;
            this.listView1.Items.Clear();

            string elemPath = dir + "\\elements.data";
            if (File.Exists(elemPath))
            {
                string[] modParts = File.GetLastWriteTime(elemPath).ToString().Split(new char[] { ' ' });
                using (BinaryReader br = new BinaryReader(File.OpenRead(elemPath)))
                {
                    int ver = (int)br.ReadInt16();
                    this.listView1.Items.Add(new ListViewItem(new string[] { "elements.data", ver.ToString(), modParts[0] }));
                }
            }

            string taskPath = dir + "\\tasks.data";
            if (File.Exists(taskPath))
            {
                string[] modParts = File.GetLastWriteTime(taskPath).ToString().Split(new char[] { ' ' });
                using (BinaryReader br = new BinaryReader(File.OpenRead(taskPath)))
                {
                    br.ReadInt32(); // magic 0x93858361
                    int ver = br.ReadInt32();
                    this.listView1.Items.Add(new ListViewItem(new string[] { "tasks.data", ver.ToString(), modParts[0] }));
                }
            }

            for (int i = 0; i < 10; i++)
            {
                string suffix = (i == 0) ? "" : i.ToString();
                string gsName = "gshop" + suffix + ".data";
                string gsPath = dir + "\\" + gsName;
                if (File.Exists(gsPath))
                {
                    string[] modParts = File.GetLastWriteTime(gsPath).ToString().Split(new char[] { ' ' });
                    using (BinaryReader br = new BinaryReader(File.OpenRead(gsPath)))
                    {
                        int ts = br.ReadInt32();
                        this.listView1.Items.Add(new ListViewItem(new string[] { gsName, "", modParts[0], timestamp_to_string(ts) }));
                    }
                }

                string gssName = "gshopsev" + suffix + ".data";
                string gssPath = dir + "\\" + gssName;
                if (File.Exists(gssPath))
                {
                    string[] modParts = File.GetLastWriteTime(gssPath).ToString().Split(new char[] { ' ' });
                    using (BinaryReader br = new BinaryReader(File.OpenRead(gssPath)))
                    {
                        int ts = br.ReadInt32();
                        this.listView1.Items.Add(new ListViewItem(new string[] { gssName, "", modParts[0], timestamp_to_string(ts) }));
                    }
                }
            }
        }

        private void btn_check_Click(object sender, EventArgs e)
        {
            FolderBrowserDialog dlg = new FolderBrowserDialog();
            dlg.ShowNewFolderButton = false;
            if (dlg.ShowDialog() == DialogResult.OK)
            {
                this.curDir = dlg.SelectedPath;
                this.popList(this.curDir);
            }
        }

        private void btnSave_Click(object sender, EventArgs e)
        {
            string outDir = Environment.CurrentDirectory;
            ListViewItem[] items = new ListViewItem[this.listView1.Items.Count];
            this.listView1.Items.CopyTo(items, 0);
            string[] lines = new string[this.listView1.Items.Count + 1];
            lines[0] = this.curDir;
            for (int i = 0; i < this.listView1.Items.Count; i++)
            {
                var subs = this.listView1.Items[i].SubItems;
                string line = subs[0].Text + " - " + subs[1].Text + " - " + subs[2].Text;
                if (subs.Count > 3)
                {
                    line += " - " + subs[3].Text;
                }
                lines[i + 1] = line;
            }
            string outPath = outDir + "\\Data Props.txt";
            File.WriteAllLines(outPath, lines);
            MessageBox.Show("Data saved to: " + outPath);
        }
    }
}
