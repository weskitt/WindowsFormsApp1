using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace WindowsFormsApp1
{
    using WordLink = Dictionary<Char, LinkProperty>;

    public class Pub
    {
        public const Char L_B = 'B';
        public const Char L_C = 'C';
        public const Char L_E = 'E';

        public const int VERB = 0; //动词
        public const int NOUN = 1; //名词
        public const int MOD = 2; //修饰词

        public const int V_NOUN = 3; //动-名
        public const int V_MOD = 4; //动-修饰
        public const int N_MOD = 5; //名-修饰

        public const int VNM = 6; //动-名-修饰
    }
    class LinkProperty
    {
        char type; //链接类型，用于分词
        int count; //链接次数，用于分权
        bool[] fun; //链接功能，语法:Verb, Noun, Mod

        public char Type { get => type; set => type = value; }
        public int Cout { get => count; set => count += value; }
        public bool this[int index] { get => fun[index]; set => fun[index] = value; }

        public LinkProperty()
        {
            type = 'O';
            count = 0;
            fun = new bool[] { false, false, false };
        }
        public LinkProperty(Char t, ref bool[] f, int c=1)
        {
            type = t;
            count = c;

            if (f[Pub.VERB])
                fun[Pub.VERB] = true; //设置该连接词性属性
            if (f[Pub.NOUN])
                fun[Pub.NOUN] = true; //设置该连接词性属性
            if (f[Pub.MOD])
                fun[Pub.MOD] = true; //设置该连接词性属性
        }
    }
    
    class Link //连接
    {
        Dictionary<Char, LinkProperty> subWords=new WordLink(); //从字,以及链接属性
        public Boolean IfLink(char key)
        {
            return subWords.ContainsKey(key);
        }
        public void AddLink(char value, char type,ref bool[] fun)
        {
            if (subWords.ContainsKey(value))
            {
                subWords[value].Cout = 1;  //存在次数+1
                if (fun[Pub.VERB])
                    subWords[value][Pub.VERB] = true; //设置该连接词性属性
                if (fun[Pub.NOUN])
                    subWords[value][Pub.NOUN] = true; //设置该连接词性属性
                if (fun[Pub.MOD])
                    subWords[value][Pub.MOD] = true; //设置该连接词性属性
            }
            else
            {
                LinkProperty link = new LinkProperty(type, ref fun);
                subWords.Add(value, link);
            }
        }
    }
    class Database //数据库
    {
        Dictionary<char, Link> wordsData; //词库
        public Boolean Ifdata(char keyWord)
        {
            return wordsData.ContainsKey(keyWord);
        }
        public void AddWords(string words, char type, ref bool[] fun)
        {
            char keyWord = words[0];
            words.Remove(0, 1);
            if (!wordsData.ContainsKey(keyWord)) //如果词首没有有记录
            {
                Link tLink = new Link();
                wordsData.Add(keyWord, tLink);
            }
            foreach (var item in words)
                    wordsData[keyWord].AddLink(item, type, ref fun);
        }
    }
    class Mem //记忆单元，暂时忽略声音影像
    {

    }
    class DepthMem //深度记忆
    {

    }
    class ShortMem //短期记忆
    {

    }
    class TempMem //临时记忆
    {

    }
    class MemObject  //记忆对象，对物理对象的镜像拷贝？储存的信息被动读取
    {
        List<Link> words;
        List<DepthMem> depthMem;
        List<ShortMem> shortMem;
        List<TempMem> tempMem;

        void recall()
        {

        } //回想
    }
}
