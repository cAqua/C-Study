// Day5.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "Pawn.h"


using namespace std;

int main()
{
    std::cout << "Hello World!\n";

#pragma region UML图
    // UML统一建模语言，

    // 继承关系  Generalization  
    // 接口实现（抽象类的实现） Interface Realization
    // 依赖关系  Dependency    B类作为A类的函数的参数或者返回值
    // 关联关系  Association   B类作为A类的成员变量 
    // 聚合关系  Aggregation   整体和部分的关系【稍微松】（汽车和轮胎）
    // 组合关系  Composition   整体和部分的关系【比较紧密】（人和脑子）
#pragma endregion

#pragma region 案例制作
    // 角色和AI拥有昵称，攻击力，防御力，HP，基础的攻击和受伤害的行为
    // 可选武器有刀和剑，有名称，基础伤害，基本攻击，两个技能攻击 
    // 锤子  笛子  绸缎  枪
    // 角色可以装配武器，有两个技能攻击，技能攻击叠加基础攻击力和武器的技能攻击
    

    // Pawn  昵称，攻击力，防御力，HP; virtual Attack(Pawn* )  ReduceHP(int ReducedHp)
    // Character角色  WeaponBase*     EquipWeapon(WeaponBase*)   UnEquipWeapon(WeaponBase*)
    //  virtual Attack(Pawn* ) override   
    //  virtual SkillAttack1(Pawn*)      virtual SkillAttack2(Pawn*)
    // 
    // AI  

    // WeaponBase   名称，基础伤害;  int Attack(Pawn* )   virtual int SkillAttack1(Pawn* ) = 0  virtual int SkillAttack2(Pawn* ) = 0
    // Dagger  virtual int SkillAttack1(Pawn* ) override       virtual int SkillAttack2(Pawn* ) overide
    // Sword  virtual int SkillAttack1(Pawn* ) override       virtual int SkillAttack2(Pawn* ) overide
    

    // 战斗过程 1V多   多V多  从文件中读取配置
    // // 寻找最近的敌人攻击    
    // // 敌我各按顺序攻击一次
    // 战斗场景
    

    

#pragma endregion

}

