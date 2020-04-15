#define GLM_FORCE_RADIANS
#include <QOpenGLFunctions_3_3_Core>
#include <QOpenGLWidget>
#include <QOpenGLShader>
#include <QOpenGLShaderProgram>
#include <QKeyEvent>
#include <QMouseEvent>
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
	// mouse events
    virtual void mousePressEvent   (QMouseEvent *event);
    virtual void mouseReleaseEvent (QMouseEvent *event);
    virtual void mouseMoveEvent    (QMouseEvent *event);


  private:
    void creaBuffers ();
    void carregaShaders ();
    void modelTransform ();
    void modelTransform2 ();
    void modelTransform3 ();
    void modelTransformTerra ();
    void projectTransform (bool ortogonal);
    void viewTransform ();
    void ini_camera ();
	void MinMaxEscena ();
	void RadiCentreEsfera ();

	typedef enum {NOINTERACCIO, ROTACIO} Interaccio;
      Interaccio DOinteraccio;

    // attribute locations
    GLuint vertexLoc, colorLoc, projLoc, viewLoc;
    // uniform locations
    GLuint transLoc;
    // VAO i VBO names
    GLuint VAO_Patricio, VAO_Ground;
    // Program
    QOpenGLShaderProgram *program;
    // Viewport
    GLint ample, alt;
    //camera
	bool ortogonal;
    float FOV, raw, zNear, zFar, factor, RadiEsfera, dist;
    glm::vec3 obs, vrp, up;
	glm::vec3 EscenaMin, EscenaMax, EscenaCentre, CentreBasePa;
	glm::vec3 eixX, eixY, eixZ;
	float theta, psi, phi, xant, yant;

    // Internal vars
    float scale, scale2;
    glm::vec3 pos;
    Model Patricio;
};
