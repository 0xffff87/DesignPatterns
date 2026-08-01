#include "website.h"

int main()
{
    WebSiteFactory *f = new WebSiteFactory();

    WebSite *fx = f->GetWebSiteCategory("产品展示");
    fx->Use(User("小菜"));

    WebSite *fy = f->GetWebSiteCategory("产品展示");
    fy->Use(User("大鸟"));

    WebSite *fz = f->GetWebSiteCategory("产品展示");
    fz->Use(User("娇娇"));

    WebSite *fl = f->GetWebSiteCategory("博客");
    fl->Use(User("老顽童"));

    WebSite *fm = f->GetWebSiteCategory("博客");
    fm->Use(User("桃谷六仙"));

    WebSite *fn = f->GetWebSiteCategory("博客");
    fn->Use(User("南海鳄神"));

    cout << "网站分类总数为: " << f->GetWebSiteCount() << endl;

    delete f;
    /*之前是直接删除每个WebSite对象，
    导致程序崩溃了
    因为不同指针指向的是同一个对象，重复释放了同一块内存
    比较好的方法是在WebSiteFactory的析构函数中释放所有的WebSite对象
    这样就不需要在main函数中手动删除每个WebSite对象了
    delete fx;
    delete fy;
    delete fz;
    delete fl;
    delete fm;
    delete fn;
    */
    delete fx;
    delete fl;
    return 0;
}