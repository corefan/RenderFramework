#ifndef _RENDER_DEFS_H_
#define _RENDER_DEFS_H_

#include <functional>

#include "Math/Vector.h"

typedef int TextureID;
typedef int ShaderID;
typedef int VertexBufferID;
typedef int IndexBufferID;
typedef int StructuredBufferID;
typedef int VertexFormatID;
typedef int SamplerStateID;
typedef int BlendStateID;
typedef int DepthStateID;
typedef int RasterizerStateID;
typedef int FontID;

struct Texture;
struct Shader;
struct VertexBuffer;
struct IndexBuffer;
struct StructuredBuffer;
struct VertexFormat;
struct SamplerState;
struct BlendState;
struct DepthState;
struct RasterizerState;

struct RenderState;
typedef std::reference_wrapper<RenderState> RenderStateRef;

enum ConstantType {
	CONSTANT_FLOAT,
	CONSTANT_VEC2,
	CONSTANT_VEC3,
	CONSTANT_VEC4,
	CONSTANT_INT,
	CONSTANT_IVEC2,
	CONSTANT_IVEC3,
	CONSTANT_IVEC4,
	CONSTANT_BOOL,
	CONSTANT_BVEC2,
	CONSTANT_BVEC3,
	CONSTANT_BVEC4,
	CONSTANT_MAT2,
	CONSTANT_MAT3,
	CONSTANT_MAT4,

	CONSTANT_TYPE_COUNT
};

extern int constantTypeSizes[CONSTANT_TYPE_COUNT];

enum Filter {
	NEAREST,
	LINEAR,
	BILINEAR,
	TRILINEAR,
	BILINEAR_ANISO,
	TRILINEAR_ANISO,
};

enum AddressMode {
	WRAP,
	CLAMP,
	BORDER,
};

#define MAKEQUAD(x0, y0, x1, y1, o)\
	vec2(x0 + o, y0 + o),\
	vec2(x0 + o, y1 - o),\
	vec2(x1 - o, y0 + o),\
	vec2(x1 - o, y1 - o),

#define MAKETEXQUAD(x0, y0, x1, y1, o)\
	TexVertex(vec2(x0 + o, y0 + o), vec2(0, 0)),\
	TexVertex(vec2(x0 + o, y1 - o), vec2(0, 1)),\
	TexVertex(vec2(x1 - o, y0 + o), vec2(1, 0)),\
	TexVertex(vec2(x1 - o, y1 - o), vec2(1, 1)),

#define MAKERECT(x0, y0, x1, y1, lw)\
	vec2(x0, y0),\
	vec2(x0 + lw, y0 + lw),\
	vec2(x1, y0),\
	vec2(x1 - lw, y0 + lw),\
	vec2(x1, y1),\
	vec2(x1 - lw, y1 - lw),\
	vec2(x0, y1),\
	vec2(x0 + lw, y1 - lw),\
	vec2(x0, y0),\
	vec2(x0 + lw, y0 + lw),


#define TEXTURE_NONE  (-1)
#define SHADER_NONE   (-1)
#define BLENDING_NONE (-1)
#define BUFFER_NONE   (-1)
#define VF_NONE   (-1)
#define VB_NONE   (-1)
#define IB_NONE   (-1)
#define SS_NONE   (-1)
#define BS_NONE   (-1)
#define DS_NONE   (-1)
#define RS_NONE   (-1)
#define FONT_NONE (-1)

#define FB_COLOR (-2)
#define FB_DEPTH (-2)
#define NO_SLICE (-1)

#define DONTCARE (-2)

// Texture flags
#define CUBEMAP             0x1
#define HALF_FLOAT          0x2
#define SRGB                0x4
#define SAMPLE_DEPTH        0x8
#define SAMPLE_SLICES       0x10
#define RENDER_SLICES       0x20
#define USE_MIPGEN          0x40
#define ADD_UAV             0x80
#define READWRITE_SLICES    0x100

// Shader flags
#define ASSEMBLY 0x1

// Mask constants
#define RED   0x1
#define GREEN 0x2
#define BLUE  0x4
#define ALPHA 0x8

#define ALL (RED | GREEN | BLUE | ALPHA)
#define NONE 0


// reset() flags
#define RESET_ALL    0xFFFF
#define RESET_SHADER 0x1
#define RESET_VF     0x2
#define RESET_VB     0x4
#define RESET_IB     0x8
#define RESET_DS     0x10
#define RESET_BS     0x20
#define RESET_RS     0x40
#define RESET_SS     0x80
#define RESET_TEX    0x100
#define RESET_UAV	 0x200
#define RESET_BUF    0x400
#define RESET_RES    (RESET_TEX | RESET_UAV | RESET_BUF | RESET_SS)

enum BufferAccess {
	STATIC,
	DEFAULT,
	DYNAMIC,
};

enum Primitives {
	PRIM_TRIANGLES = 0,
	PRIM_TRIANGLE_FAN = 1,
	PRIM_TRIANGLE_STRIP = 2,
	PRIM_QUADS = 3,
	PRIM_LINES = 4,
	PRIM_LINE_STRIP = 5,
	PRIM_LINE_LOOP = 6,
	PRIM_POINTS = 7,
};

enum AttributeType {
	TYPE_GENERIC = 0,
	TYPE_VERTEX = 1,
	TYPE_TEXCOORD = 2,
	TYPE_NORMAL = 3,
	TYPE_TANGENT = 4,
	TYPE_BITANGENT = 5,
};

enum AttributeFormat {
	FORMAT_FLOAT = 0,
	FORMAT_HALF = 1,
	FORMAT_UBYTE = 2,
};

#define MAX_MRTS 8
#define MAX_VERTEXSTREAM 8
#define MAX_UAV	8
#define MAX_TEXTUREUNIT  16
#define MAX_SAMPLERSTATE 16

// Blending constants
extern const int ZERO;
extern const int ONE;
extern const int SRC_COLOR;
extern const int ONE_MINUS_SRC_COLOR;
extern const int DST_COLOR;
extern const int ONE_MINUS_DST_COLOR;
extern const int SRC_ALPHA;
extern const int ONE_MINUS_SRC_ALPHA;
extern const int DST_ALPHA;
extern const int ONE_MINUS_DST_ALPHA;
extern const int SRC_ALPHA_SATURATE;

extern const int BM_ADD;
extern const int BM_SUBTRACT;
extern const int BM_REVERSE_SUBTRACT;
extern const int BM_MIN;
extern const int BM_MAX;

// Depth-test constants
extern const int NEVER;
extern const int LESS;
extern const int EQUAL;
extern const int LEQUAL;
extern const int GREATER;
extern const int NOTEQUAL;
extern const int GEQUAL;
extern const int ALWAYS;

// Stencil-test constants
extern const int KEEP;
extern const int SET_ZERO;
extern const int REPLACE;
extern const int INVERT;
extern const int INCR;
extern const int DECR;
extern const int INCR_SAT;
extern const int DECR_SAT;

// Culling constants
extern const int CULL_NONE;
extern const int CULL_BACK;
extern const int CULL_FRONT;

// Fillmode constants
extern const int SOLID;
extern const int WIREFRAME;

#endif // _RENDER_DEFS_H_
