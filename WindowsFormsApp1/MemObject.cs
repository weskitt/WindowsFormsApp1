using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace WindowsFormsApp1
{
    class WordProperty
    {
        char type; //链接类型，用于分词
        int cout; //链接次数，用于分权
        char fun; //链接功能，语法:Verb, Noun, ADJ, ADV

        public char Type { get => type; set => type = value; }
        public int Cout { get => cout; set => cout = value; }
        public char Fun { get => fun; set => fun = value; }
    }
    class Word //字库
    {
        Char mWord; //主字
        Dictionary<Char,int> subWords; //从字,以及链接次数

        public char MWord { get => mWord; set => mWord = value; }
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
        List<Word> words;
        List<DepthMem> depthMem;
        List<ShortMem> shortMem;
        List<TempMem> tempMem;

        void recall()
        {

        } //回想
    }
}
