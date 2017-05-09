namespace WindowsFormsApp1
{
    partial class Form1
    {
        /// <summary>
        /// 必需的设计器变量。
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// 清理所有正在使用的资源。
        /// </summary>
        /// <param name="disposing">如果应释放托管资源，为 true；否则为 false。</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows 窗体设计器生成的代码

        /// <summary>
        /// 设计器支持所需的方法 - 不要修改
        /// 使用代码编辑器修改此方法的内容。
        /// </summary>
        private void InitializeComponent()
        {
            this.TextBox = new System.Windows.Forms.RichTextBox();
            this.StrText = new System.Windows.Forms.TextBox();
            this.SuspendLayout();
            // 
            // TextBox
            // 
            this.TextBox.Location = new System.Drawing.Point(13, 13);
            this.TextBox.Name = "TextBox";
            this.TextBox.ReadOnly = true;
            this.TextBox.Size = new System.Drawing.Size(494, 509);
            this.TextBox.TabIndex = 0;
            this.TextBox.Text = "";
            // 
            // StrText
            // 
            this.StrText.Location = new System.Drawing.Point(13, 529);
            this.StrText.Name = "StrText";
            this.StrText.Size = new System.Drawing.Size(494, 28);
            this.StrText.TabIndex = 1;
            this.StrText.KeyPress += new System.Windows.Forms.KeyPressEventHandler(this.StrText_KeyPress);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(9F, 18F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(519, 675);
            this.Controls.Add(this.StrText);
            this.Controls.Add(this.TextBox);
            this.Name = "Form1";
            this.Text = "Form1";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.RichTextBox TextBox;
        private System.Windows.Forms.TextBox StrText;
    }
}

