#define GLM_FORCE_RADIANS
#include <QOpenGLFunctions_3_3_Core>
#include <QOpenGLWidget>
#include <QOpenGLShader>
#include <QOpenGLShaderProgram>
#include <QKeyEvent>
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "model.h"

class MyGLWidget : public QOpenGLWidget, protected QOpenGLFunctions_3_3_Core
{
  Q_OBJECT

  public:
    MyGLWidget (QWidget *parent=0);
    ~MyGLWidget ();

  protected:
    // initializeGL - Aqui incluim les inicialitzacions del contexte grafic.
    virtual void initializeGL ( );
    // paintGL - Mètode cridat cada cop que cal refrescar la finestra.
    // Tot el que es dibuixa es dibuixa aqui.
    virtual void paintGL ( );
    // resizeGL - És cridat quan canvia la mida del widget
    virtual void resizeGL (int width, int height);
    // keyPressEvent - Es cridat quan es prem una tecla
    virtual void keyPressEvent (QKeyEvent *event);
    // projectTransform - Es cridat quan transformem la


  private:
    void creaBuffers ();
    void carregaShaders ();
    void modelTransform ();
    void modelTransformTerra ();
    void projectTransform ();
    void viewTransform ();
    void ini_camera ();


    // attribute locations
    GLuint vertexLoc, colorLoc, projLoc, viewLoc;
    // uniform locations
    GLuint transLoc;
    // VAO i VBO names
    GLuint VAO_Homer, VAO_Ground;
    // Program
    QOpenGLShaderProgram *program;
    // Viewport
    GLint ample, alt;
    //camera
    float FOV, raw, zNear, zFar, factor;
    glm::vec3 obs, vrp, up;
    // Internal vars
    float scale;
    glm::vec3 pos;
    Model homer;
};
