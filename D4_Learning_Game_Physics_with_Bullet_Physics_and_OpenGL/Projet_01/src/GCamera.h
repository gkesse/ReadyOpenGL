//===============================================
#ifndef _GCamera_
#define _GCamera_
//===============================================
#include <GL/freeglut.h>
#include <BulletDynamics/Dynamics/btDynamicsWorld.h>
//===============================================
class GCamera {
public:
    GCamera();
    ~GCamera();

public:
    static GCamera* Instance();
    void setWindowSize(int w, int h);
    void update();

private:
    static GCamera* m_instance;
    int m_screenW;
    int m_screenH;
    btVector3 m_cameraPos;
    btVector3 m_targetPos;
    btVector3 m_upVec;
    float m_near;
    float m_far;
    float m_cameraDist;
    float m_cameraPitch;
    float m_cameraYaw;
};
//===============================================
#endif
//===============================================
