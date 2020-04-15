#include "MyGLWidget.h"

#include <iostream>

MyGLWidget::MyGLWidget (QWidget* parent) : QOpenGLWidget(parent), program(NULL) {
  setFocusPolicy(Qt::StrongFocus);  // per rebre events de teclat
  scale = 1.0f;
}

MyGLWidget::~MyGLWidget () {
  if (program != NULL)
    delete program;
}

void MyGLWidget::initializeGL () {
  // Cal inicialitzar l'ús de les funcions d'OpenGL
  initializeOpenGLFunctions();
  ortogonal = false;
  glClearColor(0.5, 0.7, 1.0, 1.0); // defineix color de fons (d'esborrat)
  glEnable (GL_DEPTH_TEST);

  carregaShaders();
  creaBuffers();

  MinMaxEscena();
  RadiCentreEsfera();

  ini_camera();
}

void MyGLWidget::paintGL () {
// En cas de voler canviar els paràmetres del viewport, descomenteu la crida següent i
// useu els paràmetres que considereu (els que hi ha són els de per defecte)
//glViewport (0, 0, ample, alt);
glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  // Carreguem la transformació de model
  // Esborrem el frame-buffer

  viewTransform ();
  projectTransform(ortogonal);

  // Activem el VAO per a pintar la caseta
  glBindVertexArray (VAO_Patricio);
  // pintem els 3 patricios
  modelTransform ();
  glDrawArrays(GL_TRIANGLES, 0, sizeof(GLfloat) * Patricio.faces().size() * 3);
  modelTransform2 ();
  glDrawArrays(GL_TRIANGLES, 0, sizeof(GLfloat) * Patricio.faces().size() * 3);
  modelTransform3 ();
  glDrawArrays(GL_TRIANGLES, 0, sizeof(GLfloat) * Patricio.faces().size() * 3);


  glBindVertexArray (VAO_Ground);
  modelTransformTerra();
  // pintem
  glDrawArrays(GL_TRIANGLES, 0, 6);

  glBindVertexArray (0);
}

void MyGLWidget::modelTransform () {
  // Matriu de transformació de model
  glm::mat4 transform (1.0f);
  transform = glm::rotate(transform,factor, glm::vec3(0,1,0));
  transform = glm::scale(transform, glm::vec3(scale));
  transform = glm::translate(transform, glm::vec3(2,0,2));
  transform = glm::scale(transform, glm::vec3(scale2));
  transform = glm::translate(transform, -CentreBasePa);
  glUniformMatrix4fv(transLoc, 1, GL_FALSE, &transform[0][0]);

}

void MyGLWidget::modelTransform2 () {
  // Matriu de transformació de model
  glm::mat4 transform (1.0f);
  transform = glm::rotate(transform,factor+float(M_PI/2.0), glm::vec3(0,1,0));
  transform = glm::scale(transform, glm::vec3(scale));
  transform = glm::scale(transform, glm::vec3(scale2));
  transform = glm::translate(transform, -CentreBasePa);
  glUniformMatrix4fv(transLoc, 1, GL_FALSE, &transform[0][0]);

}

void MyGLWidget::modelTransform3 () {
  // Matriu de transformació de model
  glm::mat4 transform (1.0f);
  transform = glm::rotate(transform,factor+float(M_PI), glm::vec3(0,1,0));
  transform = glm::scale(transform, glm::vec3(scale));
  transform = glm::translate(transform, glm::vec3(2,0,2));
  transform = glm::scale(transform, glm::vec3(scale2));
  transform = glm::translate(transform, -CentreBasePa);
  glUniformMatrix4fv(transLoc, 1, GL_FALSE, &transform[0][0]);

}

void MyGLWidget::modelTransformTerra () {
  // Matriu de transformació de model
  glm::mat4 transform (1.0f);
  //transform = glm::scale(transform, glm::vec3(scale2));
  glUniformMatrix4fv(transLoc, 1, GL_FALSE, &transform[0][0]);
}


void MyGLWidget::resizeGL (int w, int h)
  {
	 raw = float(w)/float(h);
	 projectTransform(ortogonal);
	 glViewport(0, 0, w, h);
  }

void MyGLWidget::ini_camera () {
	eixX = glm::vec3(1.,0.,0.);
	eixY = glm::vec3(0.,1.,0.);
	eixZ = glm::vec3(0.,0.,1.);
	theta = psi = phi = xant = yant = 0.0;
	DOinteraccio = NOINTERACCIO;

	vrp = EscenaCentre;
	dist = RadiEsfera * 2.0f;
	obs = vrp + glm::vec3(0, 0, dist);
	up = glm::vec3(0,1,0);
    raw = 1.0f;
    zNear = (dist - RadiEsfera)/2;
    zFar = dist + RadiEsfera;
	FOV = 2.0 * asin(RadiEsfera / dist);
}

void MyGLWidget::projectTransform (bool ortogonal) {
    glm::mat4 Proj;
	float fov;

	if (raw < 1.0) {
		fov = 2.0 * atan(tan(FOV/2.0)/raw);
	}else{
		fov = FOV;
	}
	if (ortogonal){
		Proj = glm::ortho (-RadiEsfera, RadiEsfera, -RadiEsfera, RadiEsfera, zNear, zFar);
	}else{
		Proj = glm::perspective (fov, raw, zNear, zFar);
	}
    glUniformMatrix4fv (projLoc, 1, GL_FALSE, &Proj[0][0]);
}

void MyGLWidget::viewTransform () {
    glm::mat4 View(1.0); //= glm::lookAt (obs, vrp, up);

	//camara a origen
	View = glm::translate (View, glm::vec3(0.0,0.0,-dist));

	//View = glm::rotate(View,-phi,eixZ);
	View = glm::rotate(View,theta,eixX);
	View = glm::rotate(View,-psi,eixY);

	//vrp a origen
	View = glm::translate(View, -vrp);
    glUniformMatrix4fv (viewLoc, 1, GL_FALSE, &View[0][0]);
}

void MyGLWidget::creaBuffers () {

  Patricio.load("./models/Patricio.obj");
  // Creació del Vertex Array Object per pintar
  glGenVertexArrays(1, &VAO_Patricio);
  glBindVertexArray(VAO_Patricio);

  GLuint VBO_Patricio[2];
  glGenBuffers(2, VBO_Patricio);
  glBindBuffer(GL_ARRAY_BUFFER, VBO_Patricio[0]);
  glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * Patricio.faces().size() * 3 * 3,Patricio.VBO_vertices(), GL_STATIC_DRAW);

  // Activem l'atribut vertexLoc
  glVertexAttribPointer(vertexLoc, 3, GL_FLOAT, GL_FALSE, 0, 0);
  glEnableVertexAttribArray(vertexLoc);

  glBindBuffer(GL_ARRAY_BUFFER, VBO_Patricio[1]);
  glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * Patricio.faces().size() * 3 * 3, Patricio.VBO_matdiff(), GL_STATIC_DRAW);

  // Activem l'atribut colorLoc
  glVertexAttribPointer(colorLoc, 3, GL_FLOAT, GL_FALSE, 0, 0);
  glEnableVertexAttribArray(colorLoc);

  glm::vec3 terra[6] = {
	glm::vec3(2.5, 0.0, 2.5),
    glm::vec3(2.5, 0.0, -2.5),
    glm::vec3(-2.5, 0.0, -2.5),
    glm::vec3(2.5, 0.0, 2.5),
    glm::vec3(-2.5, 0.0, -2.5),
    glm::vec3(-2.5, 0.0, 2.5)
  };

  glm::vec3 color[6] = {
  glm::vec3(1,0,0),
  glm::vec3(0,0,1),
  glm::vec3(0,1,0),

  glm::vec3(1,0,0),
  glm::vec3(0,1,0),
  glm::vec3(0,0,1),
};

  glGenVertexArrays(1, &VAO_Ground);
  glBindVertexArray(VAO_Ground);

  GLuint VBO_GroundPos;
  glGenBuffers(2, &VBO_GroundPos);
  glBindBuffer(GL_ARRAY_BUFFER, VBO_GroundPos);
  glBufferData(GL_ARRAY_BUFFER, sizeof(terra), terra, GL_STATIC_DRAW);

  // Activem l'atribut vertexLoc
  glVertexAttribPointer(vertexLoc, 3, GL_FLOAT, GL_FALSE, 0, 0);
  glEnableVertexAttribArray(vertexLoc);

  GLuint VBO_TerraC;
  glGenBuffers(1, &VBO_TerraC);
  glBindBuffer(GL_ARRAY_BUFFER, VBO_TerraC);
  glBufferData(GL_ARRAY_BUFFER, sizeof(color), color, GL_STATIC_DRAW);

  // Activem l'atribut colorLoc
  glVertexAttribPointer(colorLoc, 3, GL_FLOAT, GL_FALSE, 0, 0);
  glEnableVertexAttribArray(colorLoc);

  glBindVertexArray (0);

}

void MyGLWidget::MinMaxEscena() {

	//APARENTMENT INNECESSARI SI SABEM ELS VALORS A PRIORI
	float xmin,xmax,ymin,ymax,zmin,zmax;

	xmin = xmax = Patricio.vertices()[0];
	ymin = ymax = Patricio.vertices()[1];
	zmin = zmax = Patricio.vertices()[2];

	for (unsigned int i = 3; i < Patricio.vertices().size(); i += 3) {
		if (Patricio.vertices()[i+0] > xmax) xmax = Patricio.vertices()[i+0];
		if (Patricio.vertices()[i+0] < xmin) xmin = Patricio.vertices()[i+0];
		if (Patricio.vertices()[i+1] > ymax) ymax = Patricio.vertices()[i+1];
		if (Patricio.vertices()[i+1] < ymin) ymin = Patricio.vertices()[i+1];
		if (Patricio.vertices()[i+2] > zmax) zmax = Patricio.vertices()[i+2];
		if (Patricio.vertices()[i+2] < zmin) zmin = Patricio.vertices()[i+2];
	}

	scale2 = 1.0 / (ymax - ymin);
	CentreBasePa = glm::vec3((xmin+xmax)/2, ymin, (zmin+zmax)/2);
	//EscenaMax = glm::vec3(xmax, ymax, zmax);
	//EscenaMin = glm::vec3(xmin, ymin, zmin);
	EscenaMax = glm::vec3(2.5, 1.0, 2.5);
	EscenaMin = glm::vec3(-2.5, 0.0, -2.5);
}

void MyGLWidget:: RadiCentreEsfera() {
	float deltax, deltay, deltaz;

	deltax =  EscenaMax.x - EscenaMin.x;
	deltay =  EscenaMax.y - EscenaMin.y;
	deltaz =  EscenaMax.z - EscenaMin.z;

	//RadiEsfera = sqrt(deltax * deltax + deltay * deltay + deltaz * deltaz)/2.0;
	RadiEsfera = distance(EscenaMin,EscenaMax)/2.0;
	EscenaCentre = (EscenaMax + EscenaMin) / glm::vec3(2.0);
}

void MyGLWidget::carregaShaders() {
  // Creem els shaders per al fragment shader i el vertex shader
  QOpenGLShader fs (QOpenGLShader::Fragment, this);
  QOpenGLShader vs (QOpenGLShader::Vertex, this);
  // Carreguem el codi dels fitxers i els compilem
  fs.compileSourceFile("shaders/basicShader.frag");
  vs.compileSourceFile("shaders/basicShader.vert");
  // Creem el program
  program = new QOpenGLShaderProgram(this);
  // Li afegim els shaders corresponents
  program->addShader(&fs);
  program->addShader(&vs);
  // Linkem el program
  program->link();
  // Indiquem que aquest és el program que volem usar
  program->bind();

  // Obtenim identificador per a l'atribut “vertex” del vertex shader
  vertexLoc = glGetAttribLocation (program->programId(), "vertex");
  // Obtenim identificador per a l'atribut “color” del vertex shader
  colorLoc = glGetAttribLocation (program->programId(), "color");
  // Uniform locations
  transLoc = glGetUniformLocation(program->programId(), "TG");
  projLoc = glGetUniformLocation(program->programId(),"proj");
  viewLoc = glGetUniformLocation(program->programId(),"view");
}

void MyGLWidget::keyPressEvent(QKeyEvent* event) {
  makeCurrent();
  switch (event->key()) {
    case Qt::Key_S: { // escalar a més gran
      scale += 0.05;
      break;
    }
    case Qt::Key_D: { // escalar a més petit
      scale -= 0.05;
      break;
    }
    case Qt::Key_R: { // escalar a més petit
	  factor += 0.45;
      break;
    }
	case Qt::Key_O: { // canvi de vista de la camara
      ortogonal = !ortogonal;
      break;
    }
	case Qt::Key_X: { // zoom out
      FOV += M_PI/180;
      break;
    }
	case Qt::Key_Z: { // zoom in
	  FOV -= M_PI/180;
      break;
    }
    default: event->ignore(); break;
  }
  update();
}

void MyGLWidget::mouseMoveEvent(QMouseEvent *e) {
	makeCurrent();
	int dx = abs(e->x() - xant);
	int dy = abs(e->y() - yant);

	if (dx > dy){   // gir "psi" respecte eixY
		if (e->x() > xant){
  			psi  = psi + abs(e->x() - xant) * M_PI / 180.0;
		}else if (e->x() < xant){
  			psi  = psi - abs(e->x() - xant) * M_PI / 180.0;
		}
	}else{  // gir "theta" respecte eixX
		if (e->y() > yant){
			theta = theta - abs(e->y() - yant) * M_PI / 180.0;
		}else if (e->y() < yant){
			theta = theta + abs(e->y() - yant) * M_PI / 180.0;
		}
	}
	update ();

	xant = e->x();
	yant = e->y();
}


void MyGLWidget::mousePressEvent(QMouseEvent *e) {
	makeCurrent();
	xant = e->x();
	yant = e->y();
	if (e->button() & Qt::LeftButton) {
    	DOinteraccio = ROTACIO;
	}else{
    	DOinteraccio = NOINTERACCIO;
  	}
}


void MyGLWidget::mouseReleaseEvent(QMouseEvent *e) {
	makeCurrent();
    DOinteraccio = NOINTERACCIO;
}
