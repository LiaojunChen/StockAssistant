# StockAssistant
 [项目特点](#1) 
[功能介绍](#2)  
 [代码结构](#3)  
  [功能展示](#4)  
 [与同花顺功能对比](#5)  
 [具体技术细节](#6)  
[核心代码解释部分](#7)    
 
<h1 id="1"> 项目特点</h1>
本项目设计了一个功能全面的炒股软件（对标同花顺）。在实现炒股软件所具有的所有基础功能的同时还将AI大模型融入产品交互环节，打造了一个类似于Agent的形态辅助使用，并提供了丰富的大模型选项供用户按需求选择：
- **GPT-4o** 
 响应快速，但财经专业知识较匮乏
 - **FinAssistant** 
 基于GPT-4o在OpenAI Platform上微调，加入了自己准备的财经知识，在财经领域专业知识更丰富，但响应较慢
- **Llama-3-Chinese-8B-Instruct** 
 llama3-8B的中文特调版，部署在本地推理，供尝鲜使用
 
<h1 id="2">功能介绍</h1>

**1. 实现同花顺具有的基本功能**
- 查询股票实时股价
- 买入股票
- 修改持仓（增仓，减仓）
- 今日股市行情走势展示（可查看重要指数的涨跌，热门股票）
- 数据均为本地离线保存

**2.结合GPT优化使用体验**
调用OpenAI GPT的API，并经过微调，制作了一个assistant实现以下功能：
- 每次程序启动后，针对用户持仓，提供持仓分析以及修改持仓建议
-	在用户使用搜索功能后，补充介绍搜索的股票的一些基本信息
-	可以使用文本框与GPT直接交互（chat功能）
-	每日荐股

**3.其他**
- 可将文本框输出内容一键保存，备份到邮件
<h1 id="3"> 代码结构</h1>

```mermaid
graph LR
    A[程序初始化]
    A--> C[浏览持仓信息]-->C1[使用SQLite数据库保存信息]
    A -->D[浏览股市指数走势及热门股票]-->D1[调用API以及QPixmap截取股票网页指定位置]
    A--> F[搜索股票]-->F1["使用QNetwork发送网页请求"]
    F-->F2[正则表达式提取信息]
    A--> G[修改持仓]--> G1[可进行加仓减仓等操作]
    G-->G2[使用数据库实现]
    A--> H[每日资讯]-->H1[GPT结合我们添加的知识库生成]
    A--> I[调用选择的模型进行交互]-->I1[调用OpenAI API交互]
    I-->I2[FinAssistant基于GPT-4o,加入股票知识库调教]
    I-->I3[直接调用的GPT-4o的API]
 
   
```

<h1 id="4"> 功能展示</h1>

## 模型选择展示
## 股市指数信息展示
点击combobox，选择选项可切换内容
![信息一览，左边为股市行情，右边为持仓的简明信息](https://github.com/LiaojunChen/StockAssistant/blob/main/img/pic_show.png)
![切换后展示](https://github.com/LiaojunChen/StockAssistant/blob/main/img/pic_change.png)
## 搜索功能展示
输入股票代码，点击“查询”即可获得股票信息
![图1](https://github.com/LiaojunChen/StockAssistant/blob/main/img/search.png)

### 代码鲁棒性
若输入错误的股票代码，系统会提示输入正确的股票代码
![图2](https://github.com/LiaojunChen/StockAssistant/blob/main/img/searchdebug.png)

## 修改持仓功能展示
可选择相应股票进行加仓减仓操作
![图3](https://github.com/LiaojunChen/StockAssistant/blob/main/img/changestock.png)

### 代码鲁棒性
如果输入的减仓数大于持仓数，则会提醒用户
![图4](https://github.com/LiaojunChen/StockAssistant/blob/main/img/change_debug.png)

## 每日资讯展示
结合GPT+网页新闻形成内容
![图5](https://github.com/LiaojunChen/StockAssistant/blob/main/img/news.png)
## FinAssistant持仓分析展示
软件启动后，会先用爬虫爬取持仓的最新股价，计算收益，FinAssistant会根据这些信息给出持仓分析和建议
## GPT交互展示
在文本框输入内容，即可收到GPT回复
![图6](https://github.com/LiaojunChen/StockAssistant/blob/main/img/finassistant_ouput.png)
## FinAssistant与GPT-4o对比
FinAssistant基于GPT-4-Turbo微调，加入了股票专业知识；GPT-4o使用的原生模型。
![FinAssistant](https://github.com/LiaojunChen/StockAssistant/blob/main/img/finassistant_ouput.png)
![GPT-4o](https://github.com/LiaojunChen/StockAssistant/blob/main/img/4o_outpout.png)

以上是在同样的prompt下，两个模型的回答，可以看到，GPT-4o有明显事实性错误，FinAssistant在知识库加持下更加准确严谨

<h1 id="5"> 与同花顺功能对比</h1>


|  | StockAssistant | 同花顺 |
|:--:|:--:|:--:|
| 查询实时股价格 |●|●|
| 股票建仓以及修改持仓 |●|●|
| 展示大盘走势以及行情热点 |●|●|
| 提供丰富多元的资讯信息 ||●|
| AI对话 |●|●|
| AI深度参与股票交互 |●||
| 一键信息摘录及保存|●||
<h1 id="6"> 具体技术细节</h1>

## 股票信息爬虫（GetStock.cpp）
爬虫实现。使用QNetwork库函数爬取指定网址源代码，然后用正则表达式提取关键词实现信息爬取。
## 持仓信息离线保存(SQLStock.cpp)
 使用的数据库实现（SQLite），将爬取的股票数据保存到数据库中，从而实现离线保存。其中修改持仓信息使用数据库基础语法（创建、修改、删除）等实现。
## AI模型（Core.cpp）
### GPT-4o
比较基础的调用OpenAI官方API
### FinAssistant
这部分是我们做的比较困难的一部分。一个是因为我们使用的Assistant v2今年才推出，比较新，相关教程很稀缺；另一个是即使有相关教程，代码均是python调用openai官方封装好的库，C++代码无法借鉴；同时因功能比较新，GPT自己也写不出来相关代码，只能自己啃OpenAI官方文档来学，对我们来说比较吃力。

#### 具体实现细节：
- #### 模型处理
在OpenAI Platform里用现成的工具微调。主要做的工作就是找知识信息。给其提供了A股所有上市公司基础信息（股票名称+股票代码+近年财务情况）、近一个月股市动态以及经济新闻（以解决GPT知识库落后的问题）、近半年的高质量行情研报以及资讯分析文章。
这部分
- #### 模型调用
因为几乎没有地方提供了Assistant API调用代码的C++实现版本，我们就自己写了一份，具体见：
https://blog.csdn.net/WatsonChen1188/article/details/138978083?spm=1001.2014.3001.5501
调用的过程是用json格式发送指定格式的request调用OpenAI官方API实现交互。

### Llama-3
Llama-3采用本地部署，模型选用的是Llama-3的8B版本的LoRA版本（中文强化版）（模型地址
https://github.com/ymcui/Chinese-LLaMA-Alpaca）
本地推理借助的是llama.cpp实现（项目位置
https://github.com/ggerganov/llama.cpp）
在部署Llama-3时候，我们同样发现市面上的教程基本全都是基于Linux系统或MacOS实现，跟Windows实现差异较大（可能只有我们这种小白会用Windows部署😂），之后可能会做一个windows部署的教程

## 股市走势展示（Get_Url_Pic.cpp）
先调用ScreenShot API抓取源网页截屏保存到本地，再用QPixMap截取指定位置的图片，呈现在UI上


   



<h1 id="8"> 核心代码解释部分</h1>

因篇幅较长，见核心代码解释.md
