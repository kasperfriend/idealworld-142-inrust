using System.Drawing;
using System.Windows.Forms;

namespace PW_Data_Versions
{
    partial class main
    {
        private System.ComponentModel.IContainer components = null;
        private ListView listView1;
        private ColumnHeader name;
        private ColumnHeader ver;
        private Button btn_check;
        private ColumnHeader modified;
        private ColumnHeader timestamp;
        private Label lblDir;
        private Button btnSave;
        private Label label1;

        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        private void InitializeComponent()
        {
            this.listView1 = new ListView();
            this.name = new ColumnHeader { Text = "File Name", Width = 110 };
            this.ver = new ColumnHeader { Text = "Version", Width = 70 };
            this.modified = new ColumnHeader { Text = "Last Modified", Width = 100 };
            this.timestamp = new ColumnHeader { Text = "Time Stamped", Width = 140 };
            this.btn_check = new Button { Name = "btn_check", Text = "Folder", Location = new Point(12, 12) };
            this.btnSave = new Button { Name = "btnSave", Text = "Save", Location = new Point(96, 12) };
            this.lblDir = new Label { Name = "lblDir", AutoSize = true, Location = new Point(180, 17) };
            this.label1 = new Label { Name = "label1", AutoSize = true, Location = new Point(12, 260) };

            this.listView1.Columns.AddRange(new ColumnHeader[] { this.name, this.ver, this.modified, this.timestamp });
            this.listView1.View = View.Details;
            this.listView1.FullRowSelect = true;
            this.btn_check.Click += new System.EventHandler(this.btn_check_Click);
            this.btnSave.Click += new System.EventHandler(this.btnSave_Click);

            this.ClientSize = new Size(480, 300);
            this.Controls.Add(this.listView1);
            this.Controls.Add(this.btn_check);
            this.Controls.Add(this.btnSave);
            this.Controls.Add(this.lblDir);
            this.Controls.Add(this.label1);
            this.Name = "main";
            this.Text = "PW Client Data Versions";
        }
    }
}
