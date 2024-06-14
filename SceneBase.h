#pragma once


class SceneBase
{
public:
    SceneBase();
    virtual ~SceneBase();       // 仮想関数

    virtual void Initialize();

    virtual void Update() abstract;    // 純粋仮想関数

    virtual void Draw() abstract;    // 純粋仮想関数

private:

};


