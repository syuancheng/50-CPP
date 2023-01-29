# 50-CPP

现在的开发工作要求我们能够快速掌握一门语言。一般来说应对这种挑战有两种态度：
其一，粗粗看看语法，就撸起袖子开干，边查Google边学习；
其二是花很多时间完整地把整个语言学习一遍，做到胸有成竹，然后再开始做实际工作。

然而这两种方法都有弊病。第二种方法的问题当然很明显，不仅浪费了时间，偏离了目标，而且学习效率不高。因为没有实际问题驱动的语言学习通常是不牢固不深入的。有的人学着学着成了语言专家，反而忘了自己原本是要解决问题来的。
第一种路子也有问题，在对于这种语言的脾气秉性还没有了解的情况下大刀阔斧地拼凑代码，写出来的东西肯定不入流。说穿新鞋走老路，新瓶装旧酒，那都是小问题，真正严重的是这样的程序员可以在短时间内堆积大量充满缺陷的垃圾代码。由于通常开发阶段的测试完备程度有限，这些垃圾代码往往能通过这个阶段，从而潜伏下来，在后期成为整个项目的毒瘤，反反复复让后来的维护者陷入西西弗斯困境。

实际上语言学习有一定规律可循，对于已经掌握一门语言的开发者来说，对于一般的语言，完全可以以最快的速度，在几天至一周之内掌握其最常用的50%，而且保证路子基本正宗，没有出偏的弊病。其实真正写程序不怕完全不会，最怕一知半解的去攒解决方案。因为你完全不会，就自然会去认真查书学习，如果学习能力好的话，写出来的代码质量不会差。而一知半解，自己动手土法炼钢，那搞出来的基本上都是废铜烂铁。比如错误处理和序列化，很多人不去了解“正路子”，而是凭借自己的一知半解去攒野路子，这是最危险的。因此，即使时间再紧张，这些内容也是必须首先完整了解一遍的。掌握这些内容之后进入实际开发，即使有问题，也基本不会伤及项目大体。而开发者本人则可以安步当车，慢慢在实践中提高自己。

以下列出一个学习提纲，主要针对的是有经验的人，初学者不合适。这个提纲只能用于一般的庸俗编程语言学习，目前在流行编程语言排行榜上排前20的基本上都是庸俗语言。如果你要学的是LISP之类非庸俗语言，或是某个软件中的二次开发语言，这里的建议未必合适。还是那句话，仅供参考。

 

1. 首先了解该语言的基本数据类型，基本语法和主要语言构造，主要数学运算符和print函数的使用，达到能够写谭浩强程序设计书课后数学习题的程度；

    基本数据类型， 基本语法， 主要语言构造， 数学运算符， print函数。

2. 其次掌握数组和其他集合类的使用，有基础的话可以理解一下泛型，如果理解不了也问题不大，后面可以补；
    
    数组，集合类的使用， 泛型。

3. 简单字符串处理。所谓简单，就是Regex和Parser以下的内容，什么查找替换，截断去字串之类的。不过这个阶段有一个难点，就是字符编码问题。如果理解不了，可以先跳过，否则的话最好在这时候把这个问题搞定，免留后患；
    字符串的处理， 查找替换等问题。

4. 基本面向对象或者函数式编程的特征，无非是什么继承、多态、Lambda函数之类的，如果有经验的话很快就明白了；
    继承，多态，Lambda，OOM使用。

5. 异常、错误处理、断言、日志和调试支持，对单元测试的支持。你不一定要用TDD，但是在这个时候应该掌握在这个语言里做TDD的基本技能；
    异常处理，断言，错误处理，日志，调试，单元测试。TDD？

6. 程序代码和可执行代码的组织机制，运行时模块加载、符号查找机制，这是初学时的一个难点，因为大部分书都不太注意介绍这个极为重要的内容；
    TODO:

7. 基本输入输出和文件处理，输入输出流类的组织，这通常是比较繁琐的一部分，可以提纲挈领学一下，搞清楚概念，用到的时候查就是了。到这个阶段可以写大部分控制台应用了；
    File IO

8. 该语言如何进行callback方法调用，如何支持事件驱动编程模型。在现代编程环境下，这个问题是涉及开发思想的一个核心问题，几乎每种语言在这里都会用足功夫，.NET的delegate，Java的anonymous inner class，Java 7的closure，C++OX的 tr1::function/bind，五花八门。如果能彻底理解这个问题，不但程序就不至于写得太走样，而且对该语言的设计思路也能有比较好的认识；
    TODO:

9. 如果有必要，可在这时研究regex和XML处理问题，如无必要可跳过；

10. 序列化和反序列化，掌握一下缺省的机制就可以了；

11. 如果必要，可了解一下线程、并发和异步调用机制，主要是为了读懂别人的代码，如果自己要写这类代码，必须专门花时间严肃认真系统地学习，严禁半桶水上阵；

12. 动态编程，反射和元数据编程，数据和程序之间的相互转化机制，运行时编译和执行的机制，有抱负的开发者在这块可以多下些功夫，能够使你对语言的认识高出一个层面；

13. 如果有必要，可研究一下该语言对于泛型的支持，不必花太多时间，只要能使用现成的泛型集合和泛型函数就可以了，可在以后闲暇时抽时间系统学习。需要注意的是，泛型技术跟多线程技术一样，用不好就成为万恶之源，必须系统学习，谨慎使用，否则不如不学不用；

14. 如果还有时间，最好咨询一下有经验的人，看看这个语言较常用的特色features是什么，如果之前没学过，应当补一下。比如Ruby的block interator, Java的dynamic proxy，C# 3的LINQ和extension method。没时间的话，我认为也可以边做边学，没有大问题。

15. 有必要的话，在工作的闲暇时间，可以着重考察两个问题，第一，这个语言有哪些惯用法和模式，第二，这个语言的编译/解释执行机制。

至此语言的基本部分就可以说掌握了，之后是做数据库、网络还是做图形，可以根据具体需求去搞，找相应的成熟框架或库，边做边学，加深理解。对于一个庸俗语言，我自己把上面的内容走一遍大概要花2-3周时间，不能算很快，但也耽误不了太多事情，毕竟不是每个月都学新语言。掌握了以上的内容，就给练武术打好了基本功，虽然不见得有多优秀，但是肯定是根正苗红，将来不必绕大弯子。就算是临时使用的语言，把上面这个提纲精简一下，只看蓝色重体字的部分，大致能在几天到一周内搞定，不算是太耗时，而且写出来的代码不会太不靠谱。

以上提纲未设及内存模型。对于C/C++，这个问题很重要，要放在显著位置来考虑，但对于其他语言，这个问题被透明化了，除非你要做hardcore项目，否则不必太关注。

版权声明：本文为CSDN博主「myan」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/myan/article/details/3144661

C++ Primer usage advice:

作者：dawnmist
链接：https://www.zhihu.com/question/32087709/answer/54936403
来源：知乎
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

个人经验，C++ primer 第一次可以跳着看。关键是要尽快用起来，在使用中熟练，而不是在细节中迷失。

以C++ Primer第五版为例，第一遍读的时候：Part1也就是前七章，除了6.6，6.7节，都要通读。尤其是第三章初步介绍了vector和string，简直就是新手福音，搞定这两个容器就能写一些简单的程序。Part2基本就是数据结构和算法，如果有基础读起来很轻松。9，11两章介绍的容器，以及12.1节的智能指针要通读。多用智能指针和容器，远离segment fault. 第10章里的泛型算法可以慢慢读，读完以后可以写出高逼格的函数式风格C++。12.2节讲了怎么用new和delete分配空间，题主作为新手，知道这种写法就行，写程序时尽量用容器代替原始数组，尤其是代码里最好不要有delete。Part3是块硬骨头，标题就是Tools for Class Authors. 作为一个"class user"，有些部分第一次是可以略过的。13章很重要，要细读。初始化，复制，赋值，右值引用是C++里很微妙很重要的部分，别的语言对于这些概念很少有区分得这么细的。这一章不但要精读，还要完全掌握。14章的操作符重载第一次可以观其大略；14.9节第一次可以跳过。15章讲OOP，重要性不言而喻。如果之前一点概念都没有，学起来会觉得比较抽象。网上关于OOP有很多通俗有趣的文章，可以一起看看。16章讲泛型编程，第一次读16.1节，掌握最基本的函数模板和类模板就行了。Part4就更高档了，很多内容第一次就算啃下来，长久不用又忘了。第一次读推荐把18.2节读懂，命名空间简单易用效果好。别的内容可以观其大略，用时再看。17.1节的tuple是个有趣的东东，可以读一读。17.3节的正则表达式和17.4节的随机数也许有用，也可以读一读。如果需要读写文件，要读一下17.5.2节的raw I/O和17.5.3节的random I/O。最后给题主的建议是，写C++，要尽量避免C的写法。用static_cast而不是括号转换符；用vector而不是C里面的数组；用string而不是char *；用智能指针而不是原始指针。当然I/O是个例外，printf()还是比cout好用的；转换数字和字符串时sprintf()也比stringstream快


Ref: Item2 configure： https://www.josean.com/posts/terminal-setup