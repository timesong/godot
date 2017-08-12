/* WARNING, THIS FILE WAS GENERATED, DO NOT EDIT */
#ifndef CANVAS_GLSL_HGLES2_120
#define CANVAS_GLSL_HGLES2_120


#include "drivers/gles2/shader_gles2.h"


class CanvasShaderGLES2 : public ShaderGLES2 {

	 virtual String get_shader_name() const { return "CanvasShaderGLES2"; }
public:

	enum Conditionals {
		USE_GLES_OVER_GL,
		USE_LIGHTING,
		USE_SHADOWS,
		USE_PIXEL_SNAP,
		MOMO,
		USE_MODULATE,
		SHADOW_ESM,
		USE_DISTANCE_FIELD,
		DEBUG_ENCODED_32,
		USE_NORMAL,
		USE_DEPTH_SHADOWS,
		SHADOW_PCF5,
		SHADOW_PCF13,
	};

	enum Uniforms {
		PROJECTION_MATRIX,
		MODELVIEW_MATRIX,
		EXTRA_MATRIX,
		TIME,
		LIGHT_MATRIX,
		LIGHT_LOCAL_MATRIX,
		LIGHT_POS,
		NORMAL_FLIP,
		SNAP_PIXELS,
		TEXTURE,
		SCREEN_UV_MULT,
		TEXSCREEN_SCREEN_MULT,
		TEXSCREEN_SCREEN_CLAMP,
		TEXSCREEN_TEX,
		MODULATE,
		LIGHT_TEXTURE,
		LIGHT_COLOR,
		LIGHT_SHADOW_COLOR,
		LIGHT_HEIGHT,
		LIGHT_OUTSIDE_ALPHA,
		SHADOW_TEXTURE,
		SHADOW_ATTENUATION,
		SHADOW_MATRIX,
		SHADOWPIXEL_SIZE,
		SHADOW_ESM_MULTIPLIER,
		TEXPIXEL_SIZE,
	};

	_FORCE_INLINE_ int get_uniform(Uniforms p_uniform) const { return _get_uniform(p_uniform); }

	_FORCE_INLINE_ void set_conditional(Conditionals p_conditional,bool p_enable)  {  _set_conditional(p_conditional,p_enable); }

	#define _FU if (get_uniform(p_uniform)<0) return; ERR_FAIL_COND( get_active()!=this );

 	_FORCE_INLINE_ void set_uniform(Uniforms p_uniform, float p_value) { _FU glUniform1f(get_uniform(p_uniform),p_value); }

	_FORCE_INLINE_ void set_uniform(Uniforms p_uniform, double p_value) { _FU glUniform1f(get_uniform(p_uniform),p_value); }

	_FORCE_INLINE_ void set_uniform(Uniforms p_uniform, uint8_t p_value) { _FU glUniform1i(get_uniform(p_uniform),p_value); }

	_FORCE_INLINE_ void set_uniform(Uniforms p_uniform, int8_t p_value) { _FU glUniform1i(get_uniform(p_uniform),p_value); }

	_FORCE_INLINE_ void set_uniform(Uniforms p_uniform, uint16_t p_value) { _FU glUniform1i(get_uniform(p_uniform),p_value); }

	_FORCE_INLINE_ void set_uniform(Uniforms p_uniform, int16_t p_value) { _FU glUniform1i(get_uniform(p_uniform),p_value); }

	_FORCE_INLINE_ void set_uniform(Uniforms p_uniform, uint32_t p_value) { _FU glUniform1i(get_uniform(p_uniform),p_value); }

	_FORCE_INLINE_ void set_uniform(Uniforms p_uniform, int32_t p_value) { _FU glUniform1i(get_uniform(p_uniform),p_value); }

	_FORCE_INLINE_ void set_uniform(Uniforms p_uniform, const Color& p_color) { _FU GLfloat col[4]={p_color.r,p_color.g,p_color.b,p_color.a}; glUniform4fv(get_uniform(p_uniform),1,col); }

	_FORCE_INLINE_ void set_uniform(Uniforms p_uniform, const Vector2& p_vec2) { _FU GLfloat vec2[2]={p_vec2.x,p_vec2.y}; glUniform2fv(get_uniform(p_uniform),1,vec2); }

	_FORCE_INLINE_ void set_uniform(Uniforms p_uniform, const Vector3& p_vec3) { _FU GLfloat vec3[3]={p_vec3.x,p_vec3.y,p_vec3.z}; glUniform3fv(get_uniform(p_uniform),1,vec3); }

	_FORCE_INLINE_ void set_uniform(Uniforms p_uniform, float p_a, float p_b) { _FU glUniform2f(get_uniform(p_uniform),p_a,p_b); }

	_FORCE_INLINE_ void set_uniform(Uniforms p_uniform, float p_a, float p_b, float p_c) { _FU glUniform3f(get_uniform(p_uniform),p_a,p_b,p_c); }

	_FORCE_INLINE_ void set_uniform(Uniforms p_uniform, float p_a, float p_b, float p_c, float p_d) { _FU glUniform4f(get_uniform(p_uniform),p_a,p_b,p_c,p_d); }

	_FORCE_INLINE_ void set_uniform(Uniforms p_uniform, const Transform& p_transform) {  _FU

		const Transform &tr = p_transform;

		GLfloat matrix[16]={ /* build a 16x16 matrix */
			tr.basis.elements[0][0],
			tr.basis.elements[1][0],
			tr.basis.elements[2][0],
			0,
			tr.basis.elements[0][1],
			tr.basis.elements[1][1],
			tr.basis.elements[2][1],
			0,
			tr.basis.elements[0][2],
			tr.basis.elements[1][2],
			tr.basis.elements[2][2],
			0,
			tr.origin.x,
			tr.origin.y,
			tr.origin.z,
			1
		};


	glUniformMatrix4fv(get_uniform(p_uniform),1,false,matrix);


	}

		_FORCE_INLINE_ void set_uniform(Uniforms p_uniform, const Matrix32& p_transform) {  _FU

		const Matrix32 &tr = p_transform;

		GLfloat matrix[16]={ /* build a 16x16 matrix */
			tr.elements[0][0],
			tr.elements[0][1],
			0,
			0,
			tr.elements[1][0],
			tr.elements[1][1],
			0,
			0,
			0,
			0,
			1,
			0,
			tr.elements[2][0],
			tr.elements[2][1],
			0,
			1
		};


	glUniformMatrix4fv(get_uniform(p_uniform),1,false,matrix);


	}

		_FORCE_INLINE_ void set_uniform(Uniforms p_uniform, const CameraMatrix& p_matrix) {  _FU

		GLfloat matrix[16];

		for (int i=0;i<4;i++) {
			for (int j=0;j<4;j++) {

				matrix[i*4+j]=p_matrix.matrix[i][j];
			}
		}

		glUniformMatrix4fv(get_uniform(p_uniform),1,false,matrix);
	}; 

#undef _FU


	virtual void init() {

		static const Enum *_enums=NULL;
		static const EnumValue *_enum_values=NULL;
		static const char* _conditional_strings[]={
			"#define USE_GLES_OVER_GL\n",
			"#define USE_LIGHTING\n",
			"#define USE_SHADOWS\n",
			"#define USE_PIXEL_SNAP\n",
			"#define MOMO\n",
			"#define USE_MODULATE\n",
			"#define SHADOW_ESM\n",
			"#define USE_DISTANCE_FIELD\n",
			"#define DEBUG_ENCODED_32\n",
			"#define USE_NORMAL\n",
			"#define USE_DEPTH_SHADOWS\n",
			"#define SHADOW_PCF5\n",
			"#define SHADOW_PCF13\n",
		};

		static const char* _uniform_strings[]={
			"projection_matrix",
			"modelview_matrix",
			"extra_matrix",
			"time",
			"light_matrix",
			"light_local_matrix",
			"light_pos",
			"normal_flip",
			"snap_pixels",
			"texture",
			"screen_uv_mult",
			"texscreen_screen_mult",
			"texscreen_screen_clamp",
			"texscreen_tex",
			"modulate",
			"light_texture",
			"light_color",
			"light_shadow_color",
			"light_height",
			"light_outside_alpha",
			"shadow_texture",
			"shadow_attenuation",
			"shadow_matrix",
			"shadowpixel_size",
			"shadow_esm_multiplier",
			"texpixel_size",
		};

		static AttributePair _attribute_pairs[]={
			{"vertex",0},
			{"color_attrib",3},
			{"uv_attrib",4},
		};

		static TexUnitPair *_texunit_pairs=NULL;
		static const char _vertex_code[]={
10,35,105,102,100,101,102,32,85,83,69,95,71,76,69,83,95,79,86,69,82,95,71,76,10,35,100,101,102,105,110,101,32,109,101,100,105,117,109,112,10,35,100,101,102,105,110,101,32,104,105,103,104,112,10,35,101,108,115,101,10,112,114,101,99,105,115,105,111,110,32,109,101,100,105,117,109,112,32,102,108,111,97,116,59,10,112,114,101,99,105,115,105,111,110,32,109,101,100,105,117,109,112,32,105,110,116,59,10,35,101,110,100,105,102,10,10,117,110,105,102,111,114,109,32,104,105,103,104,112,32,109,97,116,52,32,112,114,111,106,101,99,116,105,111,110,95,109,97,116,114,105,120,59,10,117,110,105,102,111,114,109,32,104,105,103,104,112,32,109,97,116,52,32,109,111,100,101,108,118,105,101,119,95,109,97,116,114,105,120,59,10,117,110,105,102,111,114,109,32,104,105,103,104,112,32,109,97,116,52,32,101,120,116,114,97,95,109,97,116,114,105,120,59,10,97,116,116,114,105,98,117,116,101,32,104,105,103,104,112,32,118,101,99,51,32,118,101,114,116,101,120,59,32,47,47,32,97,116,116,114,105,98,58,48,10,97,116,116,114,105,98,117,116,101,32,118,101,99,52,32,99,111,108,111,114,95,97,116,116,114,105,98,59,32,47,47,32,97,116,116,114,105,98,58,51,10,97,116,116,114,105,98,117,116,101,32,104,105,103,104,112,32,118,101,99,50,32,117,118,95,97,116,116,114,105,98,59,32,47,47,32,97,116,116,114,105,98,58,52,10,10,118,97,114,121,105,110,103,32,118,101,99,50,32,117,118,95,105,110,116,101,114,112,59,10,118,97,114,121,105,110,103,32,118,101,99,52,32,99,111,108,111,114,95,105,110,116,101,114,112,59,10,10,35,105,102,32,100,101,102,105,110,101,100,40,85,83,69,95,84,73,77,69,41,10,117,110,105,102,111,114,109,32,102,108,111,97,116,32,116,105,109,101,59,10,35,101,110,100,105,102,10,10,10,35,105,102,100,101,102,32,85,83,69,95,76,73,71,72,84,73,78,71,10,10,117,110,105,102,111,114,109,32,104,105,103,104,112,32,109,97,116,52,32,108,105,103,104,116,95,109,97,116,114,105,120,59,10,117,110,105,102,111,114,109,32,104,105,103,104,112,32,109,97,116,52,32,108,105,103,104,116,95,108,111,99,97,108,95,109,97,116,114,105,120,59,10,117,110,105,102,111,114,109,32,118,101,99,50,32,108,105,103,104,116,95,112,111,115,59,10,118,97,114,121,105,110,103,32,118,101,99,52,32,108,105,103,104,116,95,117,118,95,105,110,116,101,114,112,59,10,10,35,105,102,32,100,101,102,105,110,101,100,40,78,79,82,77,65,76,95,85,83,69,68,41,10,118,97,114,121,105,110,103,32,118,101,99,52,32,108,111,99,97,108,95,114,111,116,59,10,117,110,105,102,111,114,109,32,118,101,99,50,32,110,111,114,109,97,108,95,102,108,105,112,59,10,35,101,110,100,105,102,10,10,35,105,102,100,101,102,32,85,83,69,95,83,72,65,68,79,87,83,10,118,97,114,121,105,110,103,32,104,105,103,104,112,32,118,101,99,50,32,112,111,115,59,10,35,101,110,100,105,102,10,10,35,101,110,100,105,102,10,10,35,105,102,32,100,101,102,105,110,101,100,40,69,78,65,66,76,69,95,86,65,82,49,95,73,78,84,69,82,80,41,10,118,97,114,121,105,110,103,32,118,101,99,52,32,118,97,114,49,95,105,110,116,101,114,112,59,10,35,101,110,100,105,102,10,10,35,105,102,32,100,101,102,105,110,101,100,40,69,78,65,66,76,69,95,86,65,82,50,95,73,78,84,69,82,80,41,10,118,97,114,121,105,110,103,32,118,101,99,52,32,118,97,114,50,95,105,110,116,101,114,112,59,10,35,101,110,100,105,102,10,10,47,47,117,110,105,102,111,114,109,32,98,111,111,108,32,115,110,97,112,95,112,105,120,101,108,115,59,10,10,86,69,82,84,69,88,95,83,72,65,68,69,82,95,71,76,79,66,65,76,83,10,10,118,111,105,100,32,109,97,105,110,40,41,32,123,10,10,9,99,111,108,111,114,95,105,110,116,101,114,112,32,61,32,99,111,108,111,114,95,97,116,116,114,105,98,59,10,9,117,118,95,105,110,116,101,114,112,32,61,32,117,118,95,97,116,116,114,105,98,59,9,9,10,32,32,32,32,32,32,32,32,104,105,103,104,112,32,118,101,99,52,32,111,117,116,118,101,99,32,61,32,118,101,99,52,40,118,101,114,116,101,120,44,32,49,46,48,41,59,10,123,10,32,32,32,32,32,32,32,32,118,101,99,50,32,115,114,99,95,118,116,120,61,111,117,116,118,101,99,46,120,121,59,10,86,69,82,84,69,88,95,83,72,65,68,69,82,95,67,79,68,69,10,10,125,10,35,105,102,32,33,100,101,102,105,110,101,100,40,85,83,69,95,87,79,82,76,68,95,86,69,67,41,10,32,32,32,32,32,32,32,32,111,117,116,118,101,99,32,61,32,101,120,116,114,97,95,109,97,116,114,105,120,32,42,32,111,117,116,118,101,99,59,10,32,32,32,32,32,32,32,32,111,117,116,118,101,99,32,61,32,109,111,100,101,108,118,105,101,119,95,109,97,116,114,105,120,32,42,32,111,117,116,118,101,99,59,10,35,101,110,100,105,102,10,10,10,10,35,105,102,100,101,102,32,85,83,69,95,80,73,88,69,76,95,83,78,65,80,10,10,9,111,117,116,118,101,99,46,120,121,61,102,108,111,111,114,40,111,117,116,118,101,99,46,120,121,43,48,46,53,41,59,10,35,101,110,100,105,102,10,10,10,9,103,108,95,80,111,115,105,116,105,111,110,32,61,32,112,114,111,106,101,99,116,105,111,110,95,109,97,116,114,105,120,32,42,32,111,117,116,118,101,99,59,10,10,35,105,102,100,101,102,32,85,83,69,95,76,73,71,72,84,73,78,71,10,10,9,108,105,103,104,116,95,117,118,95,105,110,116,101,114,112,46,120,121,32,61,32,40,108,105,103,104,116,95,109,97,116,114,105,120,32,42,32,111,117,116,118,101,99,41,46,120,121,59,10,9,108,105,103,104,116,95,117,118,95,105,110,116,101,114,112,46,122,119,32,61,40,108,105,103,104,116,95,108,111,99,97,108,95,109,97,116,114,105,120,32,42,32,111,117,116,118,101,99,41,46,120,121,59,10,35,105,102,100,101,102,32,85,83,69,95,83,72,65,68,79,87,83,10,9,112,111,115,61,111,117,116,118,101,99,46,120,121,59,10,35,101,110,100,105,102,10,10,35,105,102,32,100,101,102,105,110,101,100,40,78,79,82,77,65,76,95,85,83,69,68,41,10,9,108,111,99,97,108,95,114,111,116,46,120,121,61,110,111,114,109,97,108,105,122,101,40,32,40,109,111,100,101,108,118,105,101,119,95,109,97,116,114,105,120,32,42,32,40,32,101,120,116,114,97,95,109,97,116,114,105,120,32,42,32,118,101,99,52,40,49,46,48,44,48,46,48,44,48,46,48,44,48,46,48,41,32,41,41,46,120,121,32,32,41,42,110,111,114,109,97,108,95,102,108,105,112,46,120,59,10,9,108,111,99,97,108,95,114,111,116,46,122,119,61,110,111,114,109,97,108,105,122,101,40,32,40,109,111,100,101,108,118,105,101,119,95,109,97,116,114,105,120,32,42,32,40,32,101,120,116,114,97,95,109,97,116,114,105,120,32,42,32,118,101,99,52,40,48,46,48,44,49,46,48,44,48,46,48,44,48,46,48,41,32,41,41,46,120,121,32,32,41,42,110,111,114,109,97,108,95,102,108,105,112,46,121,59,10,35,101,110,100,105,102,10,10,35,101,110,100,105,102,10,10,125,10,10,		0};

		static const int _vertex_code_start=1;
		static const char _fragment_code[]={
10,35,105,102,100,101,102,32,85,83,69,95,71,76,69,83,95,79,86,69,82,95,71,76,10,35,100,101,102,105,110,101,32,109,101,100,105,117,109,112,10,35,100,101,102,105,110,101,32,104,105,103,104,112,10,35,101,108,115,101,10,112,114,101,99,105,115,105,111,110,32,109,101,100,105,117,109,112,32,102,108,111,97,116,59,10,112,114,101,99,105,115,105,111,110,32,109,101,100,105,117,109,112,32,105,110,116,59,10,35,101,110,100,105,102,10,10,32,47,47,32,116,101,120,117,110,105,116,58,48,10,117,110,105,102,111,114,109,32,115,97,109,112,108,101,114,50,68,32,116,101,120,116,117,114,101,59,10,10,118,97,114,121,105,110,103,32,118,101,99,50,32,117,118,95,105,110,116,101,114,112,59,10,118,97,114,121,105,110,103,32,118,101,99,52,32,99,111,108,111,114,95,105,110,116,101,114,112,59,10,10,35,105,102,100,101,102,32,77,79,77,79,10,10,35,101,110,100,105,102,10,10,35,105,102,32,100,101,102,105,110,101,100,40,69,78,65,66,76,69,95,83,67,82,69,69,78,95,85,86,41,10,10,117,110,105,102,111,114,109,32,118,101,99,50,32,115,99,114,101,101,110,95,117,118,95,109,117,108,116,59,10,10,35,101,110,100,105,102,10,10,35,105,102,32,100,101,102,105,110,101,100,40,69,78,65,66,76,69,95,84,69,88,83,67,82,69,69,78,41,10,10,117,110,105,102,111,114,109,32,118,101,99,50,32,116,101,120,115,99,114,101,101,110,95,115,99,114,101,101,110,95,109,117,108,116,59,10,117,110,105,102,111,114,109,32,118,101,99,52,32,116,101,120,115,99,114,101,101,110,95,115,99,114,101,101,110,95,99,108,97,109,112,59,10,117,110,105,102,111,114,109,32,115,97,109,112,108,101,114,50,68,32,116,101,120,115,99,114,101,101,110,95,116,101,120,59,10,10,35,101,110,100,105,102,10,10,10,35,105,102,32,100,101,102,105,110,101,100,40,69,78,65,66,76,69,95,86,65,82,49,95,73,78,84,69,82,80,41,10,118,97,114,121,105,110,103,32,118,101,99,52,32,118,97,114,49,95,105,110,116,101,114,112,59,10,35,101,110,100,105,102,10,10,35,105,102,32,100,101,102,105,110,101,100,40,69,78,65,66,76,69,95,86,65,82,50,95,73,78,84,69,82,80,41,10,118,97,114,121,105,110,103,32,118,101,99,52,32,118,97,114,50,95,105,110,116,101,114,112,59,10,35,101,110,100,105,102,10,10,35,105,102,32,100,101,102,105,110,101,100,40,85,83,69,95,84,73,77,69,41,10,117,110,105,102,111,114,109,32,102,108,111,97,116,32,116,105,109,101,59,10,35,101,110,100,105,102,10,10,35,105,102,100,101,102,32,85,83,69,95,77,79,68,85,76,65,84,69,10,10,117,110,105,102,111,114,109,32,118,101,99,52,32,109,111,100,117,108,97,116,101,59,10,10,35,101,110,100,105,102,10,10,35,105,102,100,101,102,32,85,83,69,95,76,73,71,72,84,73,78,71,10,10,117,110,105,102,111,114,109,32,115,97,109,112,108,101,114,50,68,32,108,105,103,104,116,95,116,101,120,116,117,114,101,59,10,117,110,105,102,111,114,109,32,118,101,99,52,32,108,105,103,104,116,95,99,111,108,111,114,59,10,117,110,105,102,111,114,109,32,118,101,99,52,32,108,105,103,104,116,95,115,104,97,100,111,119,95,99,111,108,111,114,59,10,117,110,105,102,111,114,109,32,102,108,111,97,116,32,108,105,103,104,116,95,104,101,105,103,104,116,59,10,118,97,114,121,105,110,103,32,118,101,99,52,32,108,105,103,104,116,95,117,118,95,105,110,116,101,114,112,59,10,117,110,105,102,111,114,109,32,102,108,111,97,116,32,108,105,103,104,116,95,111,117,116,115,105,100,101,95,97,108,112,104,97,59,10,10,35,105,102,32,100,101,102,105,110,101,100,40,78,79,82,77,65,76,95,85,83,69,68,41,10,118,97,114,121,105,110,103,32,118,101,99,52,32,108,111,99,97,108,95,114,111,116,59,10,35,101,110,100,105,102,10,10,35,105,102,100,101,102,32,85,83,69,95,83,72,65,68,79,87,83,10,10,117,110,105,102,111,114,109,32,104,105,103,104,112,32,115,97,109,112,108,101,114,50,68,32,115,104,97,100,111,119,95,116,101,120,116,117,114,101,59,10,117,110,105,102,111,114,109,32,102,108,111,97,116,32,115,104,97,100,111,119,95,97,116,116,101,110,117,97,116,105,111,110,59,10,10,117,110,105,102,111,114,109,32,104,105,103,104,112,32,109,97,116,52,32,115,104,97,100,111,119,95,109,97,116,114,105,120,59,10,118,97,114,121,105,110,103,32,104,105,103,104,112,32,118,101,99,50,32,112,111,115,59,10,117,110,105,102,111,114,109,32,102,108,111,97,116,32,115,104,97,100,111,119,112,105,120,101,108,95,115,105,122,101,59,10,10,35,105,102,100,101,102,32,83,72,65,68,79,87,95,69,83,77,10,117,110,105,102,111,114,109,32,102,108,111,97,116,32,115,104,97,100,111,119,95,101,115,109,95,109,117,108,116,105,112,108,105,101,114,59,10,35,101,110,100,105,102,10,10,35,101,110,100,105,102,10,10,35,101,110,100,105,102,10,10,35,105,102,32,100,101,102,105,110,101,100,40,85,83,69,95,84,69,88,80,73,88,69,76,95,83,73,90,69,41,10,117,110,105,102,111,114,109,32,118,101,99,50,32,116,101,120,112,105,120,101,108,95,115,105,122,101,59,10,35,101,110,100,105,102,10,10,10,70,82,65,71,77,69,78,84,95,83,72,65,68,69,82,95,71,76,79,66,65,76,83,10,10,10,118,111,105,100,32,109,97,105,110,40,41,32,123,10,10,9,118,101,99,52,32,99,111,108,111,114,32,61,32,99,111,108,111,114,95,105,110,116,101,114,112,59,10,35,105,102,32,100,101,102,105,110,101,100,40,78,79,82,77,65,76,95,85,83,69,68,41,10,9,118,101,99,51,32,110,111,114,109,97,108,32,61,32,118,101,99,51,40,48,46,48,44,48,46,48,44,49,46,48,41,59,10,35,101,110,100,105,102,10,10,35,105,102,100,101,102,32,85,83,69,95,68,73,83,84,65,78,67,69,95,70,73,69,76,68,10,9,99,111,110,115,116,32,102,108,111,97,116,32,115,109,111,111,116,104,105,110,103,32,61,32,49,46,48,47,51,50,46,48,59,10,9,102,108,111,97,116,32,100,105,115,116,97,110,99,101,32,61,32,116,101,120,116,117,114,101,50,68,40,116,101,120,116,117,114,101,44,32,117,118,95,105,110,116,101,114,112,41,46,97,59,10,9,99,111,108,111,114,46,97,32,61,32,115,109,111,111,116,104,115,116,101,112,40,48,46,53,32,45,32,115,109,111,111,116,104,105,110,103,44,32,48,46,53,32,43,32,115,109,111,111,116,104,105,110,103,44,32,100,105,115,116,97,110,99,101,41,32,42,32,99,111,108,111,114,46,97,59,10,35,101,108,115,101,10,9,99,111,108,111,114,32,42,61,32,116,101,120,116,117,114,101,50,68,40,32,116,101,120,116,117,114,101,44,32,32,117,118,95,105,110,116,101,114,112,32,41,59,10,10,35,101,110,100,105,102,10,10,10,35,105,102,32,100,101,102,105,110,101,100,40,69,78,65,66,76,69,95,83,67,82,69,69,78,95,85,86,41,10,9,118,101,99,50,32,115,99,114,101,101,110,95,117,118,32,61,32,103,108,95,70,114,97,103,67,111,111,114,100,46,120,121,42,115,99,114,101,101,110,95,117,118,95,109,117,108,116,59,10,35,101,110,100,105,102,10,10,10,123,10,35,105,102,32,100,101,102,105,110,101,100,40,85,83,69,95,78,79,82,77,65,76,77,65,80,41,10,9,118,101,99,51,32,110,111,114,109,97,108,95,109,97,112,61,118,101,99,51,40,48,46,48,44,48,46,48,44,49,46,48,41,59,10,9,102,108,111,97,116,32,110,111,114,109,97,108,95,100,101,112,116,104,61,49,46,48,59,10,35,101,110,100,105,102,10,10,70,82,65,71,77,69,78,84,95,83,72,65,68,69,82,95,67,79,68,69,10,10,35,105,102,32,100,101,102,105,110,101,100,40,85,83,69,95,78,79,82,77,65,76,77,65,80,41,10,9,110,111,114,109,97,108,32,61,32,109,105,120,40,118,101,99,51,40,48,46,48,44,48,46,48,44,49,46,48,41,44,32,110,111,114,109,97,108,95,109,97,112,32,42,32,118,101,99,51,40,50,46,48,44,45,50,46,48,44,49,46,48,41,32,45,32,118,101,99,51,40,32,49,46,48,44,32,45,49,46,48,44,32,48,46,48,32,41,44,32,110,111,114,109,97,108,95,100,101,112,116,104,32,41,59,10,35,101,110,100,105,102,10,10,125,10,35,105,102,100,101,102,32,68,69,66,85,71,95,69,78,67,79,68,69,68,95,51,50,10,9,104,105,103,104,112,32,102,108,111,97,116,32,101,110,99,51,50,32,61,32,100,111,116,40,32,99,111,108,111,114,44,104,105,103,104,112,32,118,101,99,52,40,49,46,48,32,47,32,40,50,53,54,46,48,32,42,32,50,53,54,46,48,32,42,32,50,53,54,46,48,41,44,49,46,48,32,47,32,40,50,53,54,46,48,32,42,32,50,53,54,46,48,41,44,49,46,48,32,47,32,50,53,54,46,48,44,49,41,32,32,41,59,10,9,99,111,108,111,114,32,61,32,118,101,99,52,40,118,101,99,51,40,101,110,99,51,50,41,44,49,46,48,41,59,10,35,101,110,100,105,102,10,10,35,105,102,100,101,102,32,85,83,69,95,77,79,68,85,76,65,84,69,10,10,9,99,111,108,111,114,42,61,109,111,100,117,108,97,116,101,59,10,35,101,110,100,105,102,10,10,10,35,105,102,100,101,102,32,85,83,69,95,76,73,71,72,84,73,78,71,10,10,9,118,101,99,50,32,108,105,103,104,116,95,118,101,99,32,61,32,108,105,103,104,116,95,117,118,95,105,110,116,101,114,112,46,122,119,59,59,32,47,47,102,111,114,32,115,104,97,100,111,119,32,97,110,100,32,110,111,114,109,97,108,32,109,97,112,112,105,110,103,10,10,35,105,102,32,100,101,102,105,110,101,100,40,78,79,82,77,65,76,95,85,83,69,68,41,10,9,110,111,114,109,97,108,46,120,121,32,61,32,32,109,97,116,50,40,108,111,99,97,108,95,114,111,116,46,120,121,44,108,111,99,97,108,95,114,111,116,46,122,119,41,32,42,32,110,111,114,109,97,108,46,120,121,59,10,35,101,110,100,105,102,10,10,9,102,108,111,97,116,32,97,116,116,61,49,46,48,59,10,10,9,118,101,99,50,32,108,105,103,104,116,95,117,118,32,61,32,108,105,103,104,116,95,117,118,95,105,110,116,101,114,112,46,120,121,59,10,9,118,101,99,52,32,108,105,103,104,116,32,61,32,116,101,120,116,117,114,101,50,68,40,108,105,103,104,116,95,116,101,120,116,117,114,101,44,108,105,103,104,116,95,117,118,41,32,42,32,108,105,103,104,116,95,99,111,108,111,114,59,10,35,105,102,32,100,101,102,105,110,101,100,40,85,83,69,95,79,85,84,80,85,84,95,83,72,65,68,79,87,95,67,79,76,79,82,41,10,9,118,101,99,52,32,115,104,97,100,111,119,95,99,111,108,111,114,61,118,101,99,52,40,48,46,48,44,48,46,48,44,48,46,48,44,48,46,48,41,59,10,35,101,110,100,105,102,10,10,9,105,102,32,40,97,110,121,40,108,101,115,115,84,104,97,110,40,108,105,103,104,116,95,117,118,95,105,110,116,101,114,112,46,120,121,44,118,101,99,50,40,48,46,48,44,48,46,48,41,41,41,32,124,124,32,97,110,121,40,103,114,101,97,116,101,114,84,104,97,110,69,113,117,97,108,40,108,105,103,104,116,95,117,118,95,105,110,116,101,114,112,46,120,121,44,118,101,99,50,40,49,46,48,44,49,46,48,41,41,41,41,32,123,10,9,9,99,111,108,111,114,46,97,42,61,108,105,103,104,116,95,111,117,116,115,105,100,101,95,97,108,112,104,97,59,32,47,47,105,110,118,105,115,105,98,108,101,10,10,9,125,32,101,108,115,101,32,123,10,10,35,105,102,32,100,101,102,105,110,101,100,40,85,83,69,95,76,73,71,72,84,95,83,72,65,68,69,82,95,67,79,68,69,41,10,47,47,108,105,103,104,116,32,105,115,32,119,114,105,116,116,101,110,32,98,121,32,116,104,101,32,108,105,103,104,116,32,115,104,97,100,101,114,10,9,9,123,10,9,9,9,118,101,99,52,32,108,105,103,104,116,95,111,117,116,61,108,105,103,104,116,42,99,111,108,111,114,59,10,76,73,71,72,84,95,83,72,65,68,69,82,95,67,79,68,69,10,9,9,9,99,111,108,111,114,61,108,105,103,104,116,95,111,117,116,59,10,9,9,125,10,10,35,101,108,115,101,10,10,35,105,102,32,100,101,102,105,110,101,100,40,78,79,82,77,65,76,95,85,83,69,68,41,10,9,9,118,101,99,51,32,108,105,103,104,116,95,110,111,114,109,97,108,32,61,32,110,111,114,109,97,108,105,122,101,40,118,101,99,51,40,108,105,103,104,116,95,118,101,99,44,45,108,105,103,104,116,95,104,101,105,103,104,116,41,41,59,10,9,9,108,105,103,104,116,42,61,109,97,120,40,100,111,116,40,45,108,105,103,104,116,95,110,111,114,109,97,108,44,110,111,114,109,97,108,41,44,48,46,48,41,59,10,35,101,110,100,105,102,10,10,9,9,99,111,108,111,114,42,61,108,105,103,104,116,59,10,47,42,10,35,105,102,100,101,102,32,85,83,69,95,78,79,82,77,65,76,10,9,99,111,108,111,114,46,120,121,61,108,111,99,97,108,95,114,111,116,46,120,121,59,47,47,110,111,114,109,97,108,46,120,121,59,10,9,99,111,108,111,114,46,122,119,61,118,101,99,50,40,48,46,48,44,49,46,48,41,59,10,35,101,110,100,105,102,10,42,47,10,10,47,47,108,105,103,104,116,32,115,104,97,100,101,114,32,99,111,100,101,10,35,101,110,100,105,102,10,10,10,35,105,102,100,101,102,32,85,83,69,95,83,72,65,68,79,87,83,10,10,9,9,102,108,111,97,116,32,97,110,103,108,101,95,116,111,95,108,105,103,104,116,32,61,32,45,97,116,97,110,40,108,105,103,104,116,95,118,101,99,46,120,44,108,105,103,104,116,95,118,101,99,46,121,41,59,10,9,9,102,108,111,97,116,32,80,73,32,61,32,51,46,49,52,49,53,57,50,54,53,51,53,56,57,55,57,51,50,51,56,52,54,50,54,52,59,10,9,9,47,42,105,110,116,32,105,32,61,32,105,110,116,40,109,111,100,40,102,108,111,111,114,40,40,97,110,103,108,101,95,116,111,95,108,105,103,104,116,43,55,46,48,42,80,73,47,54,46,48,41,47,40,52,46,48,42,80,73,47,54,46,48,41,41,43,49,46,48,44,32,51,46,48,41,41,59,32,47,47,32,43,49,32,112,113,32,111,115,32,105,110,100,105,99,101,115,32,101,115,116,97,111,32,101,109,32,111,114,100,101,109,32,50,44,48,44,49,32,110,111,115,32,97,114,114,97,121,115,10,9,9,102,108,111,97,116,32,97,110,103,42,47,10,10,9,9,102,108,111,97,116,32,115,117,44,115,122,59,10,10,9,9,102,108,111,97,116,32,97,98,115,95,97,110,103,108,101,32,61,32,97,98,115,40,97,110,103,108,101,95,116,111,95,108,105,103,104,116,41,59,10,9,9,118,101,99,50,32,112,111,105,110,116,59,10,9,9,102,108,111,97,116,32,115,104,59,10,9,9,105,102,32,40,97,98,115,95,97,110,103,108,101,60,52,53,46,48,42,80,73,47,49,56,48,46,48,41,32,123,10,9,9,9,112,111,105,110,116,32,61,32,108,105,103,104,116,95,118,101,99,59,10,9,9,9,115,104,61,48,46,48,43,40,49,46,48,47,56,46,48,41,59,10,9,9,125,32,101,108,115,101,32,105,102,32,40,97,98,115,95,97,110,103,108,101,62,49,51,53,46,48,42,80,73,47,49,56,48,46,48,41,32,123,10,9,9,9,112,111,105,110,116,32,61,32,45,108,105,103,104,116,95,118,101,99,59,10,9,9,9,115,104,32,61,32,48,46,53,43,40,49,46,48,47,56,46,48,41,59,10,9,9,125,32,101,108,115,101,32,105,102,32,40,97,110,103,108,101,95,116,111,95,108,105,103,104,116,62,48,46,48,41,32,123,10,10,9,9,9,112,111,105,110,116,32,61,32,118,101,99,50,40,108,105,103,104,116,95,118,101,99,46,121,44,45,108,105,103,104,116,95,118,101,99,46,120,41,59,10,9,9,9,115,104,32,61,32,48,46,50,53,43,40,49,46,48,47,56,46,48,41,59,10,9,9,125,32,101,108,115,101,32,123,10,10,9,9,9,112,111,105,110,116,32,61,32,118,101,99,50,40,45,108,105,103,104,116,95,118,101,99,46,121,44,108,105,103,104,116,95,118,101,99,46,120,41,59,10,9,9,9,115,104,32,61,32,48,46,55,53,43,40,49,46,48,47,56,46,48,41,59,10,10,9,9,125,10,10,10,9,9,104,105,103,104,112,32,118,101,99,52,32,115,32,61,32,115,104,97,100,111,119,95,109,97,116,114,105,120,32,42,32,118,101,99,52,40,112,111,105,110,116,44,48,46,48,44,49,46,48,41,59,10,9,9,115,46,120,121,122,47,61,115,46,119,59,10,9,9,115,117,61,115,46,120,42,48,46,53,43,48,46,53,59,10,9,9,115,122,61,115,46,122,42,48,46,53,43,48,46,53,59,10,10,9,9,104,105,103,104,112,32,102,108,111,97,116,32,115,104,97,100,111,119,95,97,116,116,101,110,117,97,116,105,111,110,61,48,46,48,59,10,10,35,105,102,100,101,102,32,85,83,69,95,68,69,80,84,72,95,83,72,65,68,79,87,83,10,10,35,100,101,102,105,110,101,32,83,72,65,68,79,87,95,68,69,80,84,72,40,109,95,116,101,120,44,109,95,117,118,41,32,40,116,101,120,116,117,114,101,50,68,40,40,109,95,116,101,120,41,44,40,109,95,117,118,41,41,46,122,41,10,10,35,101,108,115,101,10,10,47,47,35,100,101,102,105,110,101,32,83,72,65,68,79,87,95,68,69,80,84,72,40,109,95,116,101,120,44,109,95,117,118,41,32,100,111,116,40,116,101,120,116,117,114,101,50,68,40,40,109,95,116,101,120,41,44,40,109,95,117,118,41,41,44,104,105,103,104,112,32,118,101,99,52,40,49,46,48,32,47,32,40,50,53,54,46,48,32,42,32,50,53,54,46,48,32,42,32,50,53,54,46,48,41,44,49,46,48,32,47,32,40,50,53,54,46,48,32,42,32,50,53,54,46,48,41,44,49,46,48,32,47,32,50,53,54,46,48,44,49,41,32,32,41,10,35,100,101,102,105,110,101,32,83,72,65,68,79,87,95,68,69,80,84,72,40,109,95,116,101,120,44,109,95,117,118,41,32,100,111,116,40,116,101,120,116,117,114,101,50,68,40,40,109,95,116,101,120,41,44,40,109,95,117,118,41,41,44,118,101,99,52,40,49,46,48,32,47,32,40,50,53,54,46,48,32,42,32,50,53,54,46,48,32,42,32,50,53,54,46,48,41,44,49,46,48,32,47,32,40,50,53,54,46,48,32,42,32,50,53,54,46,48,41,44,49,46,48,32,47,32,50,53,54,46,48,44,49,41,32,32,41,10,10,35,101,110,100,105,102,10,10,10,10,35,105,102,100,101,102,32,83,72,65,68,79,87,95,80,67,70,53,10,10,9,9,115,104,97,100,111,119,95,97,116,116,101,110,117,97,116,105,111,110,32,43,61,32,83,72,65,68,79,87,95,68,69,80,84,72,40,115,104,97,100,111,119,95,116,101,120,116,117,114,101,44,118,101,99,50,40,115,117,44,115,104,41,41,60,115,122,63,48,46,48,58,49,46,48,59,10,9,9,115,104,97,100,111,119,95,97,116,116,101,110,117,97,116,105,111,110,32,43,61,32,83,72,65,68,79,87,95,68,69,80,84,72,40,115,104,97,100,111,119,95,116,101,120,116,117,114,101,44,118,101,99,50,40,115,117,43,115,104,97,100,111,119,112,105,120,101,108,95,115,105,122,101,44,115,104,41,41,60,115,122,63,48,46,48,58,49,46,48,59,10,9,9,115,104,97,100,111,119,95,97,116,116,101,110,117,97,116,105,111,110,32,43,61,32,83,72,65,68,79,87,95,68,69,80,84,72,40,115,104,97,100,111,119,95,116,101,120,116,117,114,101,44,118,101,99,50,40,115,117,43,115,104,97,100,111,119,112,105,120,101,108,95,115,105,122,101,42,50,46,48,44,115,104,41,41,60,115,122,63,48,46,48,58,49,46,48,59,10,9,9,115,104,97,100,111,119,95,97,116,116,101,110,117,97,116,105,111,110,32,43,61,32,83,72,65,68,79,87,95,68,69,80,84,72,40,115,104,97,100,111,119,95,116,101,120,116,117,114,101,44,118,101,99,50,40,115,117,45,115,104,97,100,111,119,112,105,120,101,108,95,115,105,122,101,44,115,104,41,41,60,115,122,63,48,46,48,58,49,46,48,59,10,9,9,115,104,97,100,111,119,95,97,116,116,101,110,117,97,116,105,111,110,32,43,61,32,83,72,65,68,79,87,95,68,69,80,84,72,40,115,104,97,100,111,119,95,116,101,120,116,117,114,101,44,118,101,99,50,40,115,117,45,115,104,97,100,111,119,112,105,120,101,108,95,115,105,122,101,42,50,46,48,44,115,104,41,41,60,115,122,63,48,46,48,58,49,46,48,59,10,9,9,115,104,97,100,111,119,95,97,116,116,101,110,117,97,116,105,111,110,47,61,53,46,48,59,10,10,35,101,110,100,105,102,10,10,35,105,102,100,101,102,32,83,72,65,68,79,87,95,80,67,70,49,51,10,10,9,9,115,104,97,100,111,119,95,97,116,116,101,110,117,97,116,105,111,110,32,43,61,32,83,72,65,68,79,87,95,68,69,80,84,72,40,115,104,97,100,111,119,95,116,101,120,116,117,114,101,44,118,101,99,50,40,115,117,44,115,104,41,41,60,115,122,63,48,46,48,58,49,46,48,59,10,9,9,115,104,97,100,111,119,95,97,116,116,101,110,117,97,116,105,111,110,32,43,61,32,83,72,65,68,79,87,95,68,69,80,84,72,40,115,104,97,100,111,119,95,116,101,120,116,117,114,101,44,118,101,99,50,40,115,117,43,115,104,97,100,111,119,112,105,120,101,108,95,115,105,122,101,44,115,104,41,41,60,115,122,63,48,46,48,58,49,46,48,59,10,9,9,115,104,97,100,111,119,95,97,116,116,101,110,117,97,116,105,111,110,32,43,61,32,83,72,65,68,79,87,95,68,69,80,84,72,40,115,104,97,100,111,119,95,116,101,120,116,117,114,101,44,118,101,99,50,40,115,117,43,115,104,97,100,111,119,112,105,120,101,108,95,115,105,122,101,42,50,46,48,44,115,104,41,41,60,115,122,63,48,46,48,58,49,46,48,59,10,9,9,115,104,97,100,111,119,95,97,116,116,101,110,117,97,116,105,111,110,32,43,61,32,83,72,65,68,79,87,95,68,69,80,84,72,40,115,104,97,100,111,119,95,116,101,120,116,117,114,101,44,118,101,99,50,40,115,117,43,115,104,97,100,111,119,112,105,120,101,108,95,115,105,122,101,42,51,46,48,44,115,104,41,41,60,115,122,63,48,46,48,58,49,46,48,59,10,9,9,115,104,97,100,111,119,95,97,116,116,101,110,117,97,116,105,111,110,32,43,61,32,83,72,65,68,79,87,95,68,69,80,84,72,40,115,104,97,100,111,119,95,116,101,120,116,117,114,101,44,118,101,99,50,40,115,117,43,115,104,97,100,111,119,112,105,120,101,108,95,115,105,122,101,42,52,46,48,44,115,104,41,41,60,115,122,63,48,46,48,58,49,46,48,59,10,9,9,115,104,97,100,111,119,95,97,116,116,101,110,117,97,116,105,111,110,32,43,61,32,83,72,65,68,79,87,95,68,69,80,84,72,40,115,104,97,100,111,119,95,116,101,120,116,117,114,101,44,118,101,99,50,40,115,117,43,115,104,97,100,111,119,112,105,120,101,108,95,115,105,122,101,42,53,46,48,44,115,104,41,41,60,115,122,63,48,46,48,58,49,46,48,59,10,9,9,115,104,97,100,111,119,95,97,116,116,101,110,117,97,116,105,111,110,32,43,61,32,83,72,65,68,79,87,95,68,69,80,84,72,40,115,104,97,100,111,119,95,116,101,120,116,117,114,101,44,118,101,99,50,40,115,117,43,115,104,97,100,111,119,112,105,120,101,108,95,115,105,122,101,42,54,46,48,44,115,104,41,41,60,115,122,63,48,46,48,58,49,46,48,59,10,9,9,115,104,97,100,111,119,95,97,116,116,101,110,117,97,116,105,111,110,32,43,61,32,83,72,65,68,79,87,95,68,69,80,84,72,40,115,104,97,100,111,119,95,116,101,120,116,117,114,101,44,118,101,99,50,40,115,117,45,115,104,97,100,111,119,112,105,120,101,108,95,115,105,122,101,42,50,46,48,44,115,104,41,41,60,115,122,63,48,46,48,58,49,46,48,59,10,9,9,115,104,97,100,111,119,95,97,116,116,101,110,117,97,116,105,111,110,32,43,61,32,83,72,65,68,79,87,95,68,69,80,84,72,40,115,104,97,100,111,119,95,116,101,120,116,117,114,101,44,118,101,99,50,40,115,117,45,115,104,97,100,111,119,112,105,120,101,108,95,115,105,122,101,42,51,46,48,44,115,104,41,41,60,115,122,63,48,46,48,58,49,46,48,59,10,9,9,115,104,97,100,111,119,95,97,116,116,101,110,117,97,116,105,111,110,32,43,61,32,83,72,65,68,79,87,95,68,69,80,84,72,40,115,104,97,100,111,119,95,116,101,120,116,117,114,101,44,118,101,99,50,40,115,117,45,115,104,97,100,111,119,112,105,120,101,108,95,115,105,122,101,42,52,46,48,44,115,104,41,41,60,115,122,63,48,46,48,58,49,46,48,59,10,9,9,115,104,97,100,111,119,95,97,116,116,101,110,117,97,116,105,111,110,32,43,61,32,83,72,65,68,79,87,95,68,69,80,84,72,40,115,104,97,100,111,119,95,116,101,120,116,117,114,101,44,118,101,99,50,40,115,117,45,115,104,97,100,111,119,112,105,120,101,108,95,115,105,122,101,42,53,46,48,44,115,104,41,41,60,115,122,63,48,46,48,58,49,46,48,59,10,9,9,115,104,97,100,111,119,95,97,116,116,101,110,117,97,116,105,111,110,32,43,61,32,83,72,65,68,79,87,95,68,69,80,84,72,40,115,104,97,100,111,119,95,116,101,120,116,117,114,101,44,118,101,99,50,40,115,117,45,115,104,97,100,111,119,112,105,120,101,108,95,115,105,122,101,42,54,46,48,44,115,104,41,41,60,115,122,63,48,46,48,58,49,46,48,59,10,9,9,115,104,97,100,111,119,95,97,116,116,101,110,117,97,116,105,111,110,47,61,49,51,46,48,59,10,10,35,101,110,100,105,102,10,10,35,105,102,100,101,102,32,83,72,65,68,79,87,95,69,83,77,10,10,10,9,123,10,9,9,9,102,108,111,97,116,32,117,110,110,111,114,109,97,108,105,122,101,100,32,61,32,115,117,47,115,104,97,100,111,119,112,105,120,101,108,95,115,105,122,101,59,10,9,9,9,102,108,111,97,116,32,102,114,97,99,116,105,111,110,97,108,32,61,32,102,114,97,99,116,40,117,110,110,111,114,109,97,108,105,122,101,100,41,59,10,9,9,9,117,110,110,111,114,109,97,108,105,122,101,100,32,61,32,102,108,111,111,114,40,117,110,110,111,114,109,97,108,105,122,101,100,41,59,10,9,9,9,102,108,111,97,116,32,122,99,32,61,32,83,72,65,68,79,87,95,68,69,80,84,72,40,115,104,97,100,111,119,95,116,101,120,116,117,114,101,44,118,101,99,50,40,40,117,110,110,111,114,109,97,108,105,122,101,100,45,48,46,53,41,42,115,104,97,100,111,119,112,105,120,101,108,95,115,105,122,101,44,115,104,41,41,59,10,9,9,9,102,108,111,97,116,32,122,110,32,61,32,83,72,65,68,79,87,95,68,69,80,84,72,40,115,104,97,100,111,119,95,116,101,120,116,117,114,101,44,118,101,99,50,40,40,117,110,110,111,114,109,97,108,105,122,101,100,43,48,46,53,41,42,115,104,97,100,111,119,112,105,120,101,108,95,115,105,122,101,44,115,104,41,41,59,10,9,9,9,102,108,111,97,116,32,122,32,61,32,109,105,120,40,122,99,44,122,110,44,102,114,97,99,116,105,111,110,97,108,41,59,10,9,9,9,115,104,97,100,111,119,95,97,116,116,101,110,117,97,116,105,111,110,61,99,108,97,109,112,40,101,120,112,40,115,104,97,100,111,119,95,101,115,109,95,109,117,108,116,105,112,108,105,101,114,42,32,40,32,122,32,45,32,115,122,32,41,41,44,48,46,48,44,49,46,48,41,59,10,9,125,10,10,35,101,110,100,105,102,10,10,35,105,102,32,33,100,101,102,105,110,101,100,40,83,72,65,68,79,87,95,80,67,70,53,41,32,38,38,32,33,100,101,102,105,110,101,100,40,83,72,65,68,79,87,95,80,67,70,49,51,41,32,38,38,32,33,100,101,102,105,110,101,100,40,83,72,65,68,79,87,95,69,83,77,41,10,10,9,9,115,104,97,100,111,119,95,97,116,116,101,110,117,97,116,105,111,110,32,61,32,83,72,65,68,79,87,95,68,69,80,84,72,40,115,104,97,100,111,119,95,116,101,120,116,117,114,101,44,118,101,99,50,40,115,117,43,115,104,97,100,111,119,112,105,120,101,108,95,115,105,122,101,44,115,104,41,41,60,115,122,63,48,46,48,58,49,46,48,59,10,10,35,101,110,100,105,102,10,10,35,105,102,32,100,101,102,105,110,101,100,40,85,83,69,95,79,85,84,80,85,84,95,83,72,65,68,79,87,95,67,79,76,79,82,41,10,9,99,111,108,111,114,61,109,105,120,40,115,104,97,100,111,119,95,99,111,108,111,114,44,99,111,108,111,114,44,115,104,97,100,111,119,95,97,116,116,101,110,117,97,116,105,111,110,41,59,10,35,101,108,115,101,10,9,47,47,99,111,108,111,114,42,61,115,104,97,100,111,119,95,97,116,116,101,110,117,97,116,105,111,110,59,10,9,99,111,108,111,114,61,109,105,120,40,108,105,103,104,116,95,115,104,97,100,111,119,95,99,111,108,111,114,44,99,111,108,111,114,44,115,104,97,100,111,119,95,97,116,116,101,110,117,97,116,105,111,110,41,59,10,35,101,110,100,105,102,10,47,47,117,115,101,32,115,104,97,100,111,119,115,10,35,101,110,100,105,102,10,9,125,10,10,47,47,117,115,101,32,108,105,103,104,116,105,110,103,10,35,101,110,100,105,102,10,47,47,9,99,111,108,111,114,46,114,103,98,42,61,99,111,108,111,114,46,97,59,10,9,103,108,95,70,114,97,103,67,111,108,111,114,32,61,32,99,111,108,111,114,59,10,10,125,10,10,		0};

		static const int _fragment_code_start=98;
		setup(_conditional_strings,13,_uniform_strings,26,_attribute_pairs,3, _texunit_pairs,0,_vertex_code,_fragment_code,_vertex_code_start,_fragment_code_start);
	};

};

#endif

