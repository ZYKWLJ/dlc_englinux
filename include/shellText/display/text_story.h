// # ifndef _STORY_H
// # define _STORY_H
// # include "text_color.h"
// // 宏定义如果内容较多，要在每行末尾添加反斜杠 \ 来实现换行，并且反斜杠后面不能有任何字符（包括空格）
// #define STORY BOLD RED"《善者因之》\n"RESET\
// "契机在于一次对流层课堂上我在后面编程序，弓老师走过来问我：“同学你是在编程序？”我微微地回答：“我在看计算机的书籍（至今记忆尤深，当时再看《深入理解计算机系统》的第八章）”。没想到弓老师及其大声、认可地说："\
// "“好，编程序好，谁说对流层的课程只能干对流层的事，这不是耍流氓吗？（这句话我记忆尤深）”，此话一出，我已经被弓老师的宏大的胸襟所触动。"\
// "你喜欢编程序，那你编写一个能够实现对流层的XXX数据查询的程序”。弓老师半笑着打趣到，不过当时只是内心很触动，并非有此意向。或者说，只是种下了一颗我都不知道什么时候种下的种子。"\
// "别的老师课上只要你不好好听讲，干其他的，老师虽然不说，但或多或少会有些意见，强者金刚怒目，佛者直接不管，温者好言相劝，而只智者，善者因之。（太史公：故善者因之，其次利道 之，其次教诲之，其次整齐之，最下者与之争。这句千古名言，真正明了又几何呢？）"\
// "（非常抱歉和羞惭，我如此大胆评价教师，然而就当我是大逆不道地阐述可能存在的客观事实吧）。说实话上了大学能有这么有趣和开明的老师真是学生的（至少是我的）幸福，其实环顾当下教育，好像任何教学阶段都是如此）。\n"\
// BOLD RED"《刷视频也是好的》\n"RESET\
// "第二次契机是，我依然在最后面敲电脑，老师说了很多立志励志之言，大意就是要真正找到自己所热爱的东西，把这件事情做头，那么万事也就做透了。这个观点与我深深契合。老师还说，不一定要来教师上课，只要你说你在宿舍学高数学的十分认真专注，"\
// "效率很好，那么你不来上课完全没问题，我支持你，要打开自己的胸结。之后，弓老师走到一位同学面前问道，“同学你的爱好是什么？”，可能是看到这位同学一直在刷视频，弓老师便打趣到“你的爱好是刷视频”，听到这话，我稍微地笑了笑，"\
// "没想到弓老师来了个急转弯，大声而坚定地说“刷视频好，谁说刷视频不好，你在刷视频的同时，把制作视频的经验总结下来，这就是你的能力，这当然好啊。所以说不要限制自己，要多思维，多角度看待事情”，问君此言，顿时羞愧难当"\
// "（之前我一直认为刷视频是浪费生命，看来自己的胸结还不够打开，而弓老师定为助开此胸结之人，之贵人），再次被弓老师的博达之胸怀，广阔之视野，深远之洞见，通融之气骨所震撼、折服（至少上大学来，或者说自从上学以来，"\
// "就只有弓老师这么说过，其之伟岸通达，遇者真乃之幸运，此乃可遇不可求）（反思自身，或许真是太偏执孤傲视短眼近，要打开胸结！）。\n"\
// BOLD RED"《国际视野家国情怀》\n"RESET\
// "第三次契机便与本次软件开发深深相关了。还是这节课，我猫在最后看linux。老师走过来就问我，同学你在编程？我说我在学linux，老师就和我说了一大堆关于操作系统之国内国际事之大小，国内操作系统各方面之受垄断之窘况，"\
// "风格还是持肯定态度，而当时我正在使用的指令是tree遍历，这和这个软件的本质是相同的--数据遍历，这直接引起了我有兴趣用tree命令的风格做一些有用的开发的心思。\n"\
// BOLD RED"《宏博之视野，全维之思考》\n"RESET\
// "第四次契机是“萨拉热窝”级的（第一次世界大战引火线），也是我毛遂自荐之举之引。弓老师在群里发了一些“无关教学内容”的视频 "\
// "其中内容大概是视频制作之思维、机械构造之精巧、前人智慧之凝练诸类......"\
// "很难想象，老师和学生们发的内容基本全是与“教学无关”的，而是一些任何能够激发学生们的思维，提升学生们的能力的东西（而这事实上，貌似似之国内外教学大环境之比）。"\
// "随后我当即问之是否需要制作此程序，得知肯定后，立即展开工作，两个小时左右理清了大致框架与实现，并成功进行了数据测试。"\
// "于是，我当晚私聊了弓老师--表明构筑心志之坚与构建蓝图之伟。"\
// "虽然弓老师未教我半点技术之事，但是他确是这款软件的直接引导者，也开阔了我的视野与格局。谢谢。\n"
// # endif
#ifndef _STORY_H
#define _STORY_H
#include "text_color.h"

// Use backslash at the end of each line to continue the macro definition
#define STORY                                                                                                                                                                                                                                                                                                                                                                                                                                                             \
    BOLD RED "Inspiration from a Mentor\n" RESET                                                                                                                                                                                                                                                                                                                                                                                                                          \
             "The first spark came during a Troposphere class when I was programming at the back of the room. Professor Gong walked over and asked, 'Are you writing code?' I replied softly, 'I'm reading a computer book' (I still remember clearly it was Chapter 8 of *Computer Systems: A Programmer's Perspective*). To my surprise, Professor Gong exclaimed loudly with approval, \n"                                                                             \
             "'Good, programming is good! Who says Troposphere students can only do Troposphere-related work? That's ridiculous!' (These words left a deep impression on me.) His broad-mindedness touched me instantly.\n"                                                                                                                                                                                                                                               \
             "He added with a smile, 'Since you like programming, why not develop a program to query Troposphere data?' At the time, I was moved but didn't seriously consider it-unaware that a seed had been planted.\n"                                                                                                                                                                                                                                                \
             "Most teachers frown on students not focusing in class, but Professor Gong was different. He embodied the wisdom of Sima Qian: *The best leaders follow the natural inclinations of others; the next best guide them with benefits; the next teach them; the next enforce order; the worst contend with them.* How rare it is to encounter such a mentor!\n" BOLD RED "The Value of Diverse Interests\n" RESET                                               \
             "The second inspiration came when I was coding at the back of the class again. Professor Gong shared his philosophy: *Find what you truly love and master it deeply.* This resonated strongly with me. He even said, *If you can study calculus more effectively in your dorm, you don't need to attend class-I support you.*\n"                                                                                                                             \
             "Noticing a student scrolling through videos, he asked with a smile, 'Is watching videos your hobby?' Before the student could reply, he declared firmly, *Watching videos is great! If you analyze how they're made, you're gaining valuable skills.* This humbled me-I'd previously dismissed video-watching as a waste of time. Professor Gong taught me to embrace diverse perspectives.\n" BOLD RED "A Vision for Domestic Technology\n" RESET          \
             "The third turning point directly inspired this software. While I was studying Linux at the back of the class, Professor Gong noticed and shared insights about China's challenges with operating system monopolies. Ironically, I was using the `tree` command to traverse directories-a concept akin to data traversal in this software. This sparked my interest in developing a useful tool with a similar interface.\n" BOLD RED "The Catalyst\n" RESET \
             "The final push came when Professor Gong shared non-academic videos-about video production, mechanical ingenuity, and historical wisdom-all aimed at stimulating creativity. Inspired by his belief in interdisciplinary learning, I volunteered to develop the program. Within two hours, I outlined the framework, tested the data, and messaged him that night to commit to the project.\n"                                                               \
             "Though Professor Gong didn't teach me technical skills, he guided the creation of this software and broadened my vision. Thank you.\n"

#endif