#ifndef NODE_H
#define NODE_H

#include <QMainWindow>

#include <QTreeView>
#include <QStandardItemModel>
#include <QStandardItem>
#include <QMap>

#include "token.h"
static QList<QString> allTags{ "<!DOCTYPE>", "<a>","<abbr>",
    "<acronym>",    "<address>",    "<applet>",    "<area>",    "<article>",    "<aside>",    "<audio>",    "<b>",
    "<base>",    "<basefont>",    "<bdi>",    "<bdo>",    "<big>",    "<blockquote>",    "<body>",    "<br>",
    "<button>",    "<canvas>",    "<caption>",    "<center>",    "<cite>",    "<code>",    "<col>",    "<colgroup>",
    "<command>",    "<datalist>",    "<dd>",    "<del>",    "<details>",    "<dfn>",
    "<dir>",    "<div>",    "<dl>",    "<dt>",    "<em>",    "<embed>",    "<fieldset>",    "<figcaption>",
    "<figure>",    "<font>",    "<footer>",    "<form>",    "<frame>",    "<frameset>",    "<h1>",    "<h2>",
    "<h3>",    "<h4>",    "<h5>",    "<h6>",    "<head>",    "<header>",    "<hgroup>",    "<hr>",
    "<html>",    "<i>",    "<iframe>",    "<img>",    "<input>",    "<ins>",    "<kbd>",    "<keygen>",
    "<label>",    "<legend>",    "<li>",    "<link>",    "<map>",    "<mark>",    "<menu>",    "<meta>",
    "<meter>",    "<nav>",    "<noframes>",    "<noscript>",    "<object>",    "<ol>",    "<optgroup>",    "<option>",
    "<output>",    "<p>",    "<param>",    "<pre>",    "<progress>",    "<q>",    "<rp>",    "<rt>",
    "<ruby>",    "<s>",    "<samp>",    "<script>",    "<section>",    "<select>",    "<small>",    "<source>",
    "<span>",    "<strike>",    "<strong>",    "<style>",    "<sub>",    "<summary>",    "<sup>",    "<table>",
    "<tbody>",    "<td>",    "<textarea>",    "<tfoot>",    "<th>",    "<thead>",    "<time>",    "<title>",
    "<tr>",    "<track>",    "<tt>",    "<u>",    "<ul>",    "<var>",    "<video>",    "<wbr>"
};

class Node
{
public:
    virtual QString execute(QMap<QString , QString> table) = 0;
    virtual QStandardItem* optimize() = 0;
    virtual ~Node(){}

};

class Expression: public Node
{
public:
    QString execute(QMap<QString , QString> table) = 0;
    QStandardItem* optimize() = 0;
     ~Expression(){}
};

class DeclarationNode: public Node
{
public:
    QString id;
    QString type;
    QString execute(QMap<QString , QString> table);
    DeclarationNode(QString Type, QString Id):id{Id},type{Type}{}
    QStandardItem* optimize();

    DeclarationNode(){}
    ~DeclarationNode(){}

};

class InitialiseNode: public Node
{
public:
    Expression* expr;
    DeclarationNode* dec;
    QStandardItem* optimize();

    QString execute(QMap<QString , QString> table);
    ~InitialiseNode(){}

};

class VariableExp: public Expression{
public:
     QString id;
     VariableExp(QString Id):id{Id}{}
     QStandardItem* optimize();
     ~VariableExp(){}
     QString execute(QMap<QString , QString> table);
};

class AssingNode: public Node
{
public:
    VariableExp* var;
    Expression* expr;
    QStandardItem* optimize();
    AssingNode(){}
    QString execute(QMap<QString , QString> table);
//    ~AssingNode(){}

};

class FunctionBExp: public Expression{
public:
    functionsB type;
    Expression* param1;
    Expression* param2;
    QString execute(QMap<QString , QString> table);
    QStandardItem* optimize();
    QString find_f(QString result1, QString result2);
    QString find_all(QString result1, QString result2);
    ~FunctionBExp(){}
//    FunctionExp(QString name, QString p1, QString p2):f_name{name},param1{p1},param2{p2}{}
};

class FunctionUExp: public Expression{
public:
    functionsU type;
    Expression* param;
    QString execute(QMap<QString , QString> table);
    QString atr(QString result1);
    QStandardItem* optimize();
    QString find_next(QString result1);
    QString open(QString result1);
    ~FunctionUExp(){}
//    FunctionExp(QString name, QString p1, QString p2):f_name{name},param1{p1},param2{p2}{}
};

class StringExp: public Expression{
public:
    QString value;
    StringExp(QString string):value{string}{}
    QStandardItem* optimize();
    QString execute(QMap<QString , QString> table);
    ~StringExp(){}
};

class HTML_TagExp: public Expression{
public:
    QString value;
    HTML_TagExp(QString string):value{string}{}
    QStandardItem* optimize();
    QString execute(QMap<QString , QString> table);
    ~HTML_TagExp(){}
};

class CurlBracStm: public Node{
    public:
    QVector<Node*> body;
    int startingNode;
    int endingNode;
    QStandardItem* optimize();
    QString execute(QMap<QString , QString> table);
    ~CurlBracStm(){}

};

class IfStm: public Node{
public:
    bool alwaysTrue = false;
    bool alwaysFalse = false;
    Expression* condition;
    CurlBracStm* body;
    static bool checkCondition(Expression* condition, QMap<QString, QString> table);
    QStandardItem* optimize();
    QString execute(QMap<QString , QString> table);
    ~IfStm(){}
};

class WhileStm: public Node{
public:
    bool alwaysTrue = false;
    bool alwaysFalse = false;
    Expression* condition;
    CurlBracStm* body;
    QStandardItem* optimize();
    QString execute(QMap<QString , QString> table);
    ~WhileStm(){}
};




#endif // NODE_H
