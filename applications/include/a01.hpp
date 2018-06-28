#ifndef ASSIGNMENT_1_HPP
#define ASSIGNMENT_1_HPP
#include "application.hpp"

#include <glm/glm.hpp>

#include "helper.hpp"
#include "models.hpp"

class Assignment1 : public Application {
 public:
  // allocate and initialize objects
  Assignment1(std::string const& resource_path);
  Assignment1(Assignment1 const&) = delete;
  Assignment1& operator=(Assignment1 const&) = delete;

  // draw all objects
  void render();

 protected:
  // common methods
  void initializeGUI();
  void initializeShaderPrograms();
  void initializeObjects();

  void renderScene() const;
  float splatDistFromOrigin() const;
  void drawSplats(const int program, const float radius, const bool asLight) const;
  void resize() override;
  // render objects
  simpleQuad  quad;
  simpleModel teaPot;
  groundPlane plane;
  solidSphere sphere;
  simplePoint point;

  // frame buffer object
  Fbo fbo;

  // textures
  Tex diffuse;
  Tex normal;
  Tex position; 
  Tex depth;

  Timer timer;

  glm::fvec3 lightDir;
  float rotationAngle;
  float degreesPerSecond;
  float radius;

  bool autoRotate;
  bool debugShading;
  bool stencilCulling;
  bool debugStencil;
  bool clearDebugStencil;
  bool splatting;
};

#endif