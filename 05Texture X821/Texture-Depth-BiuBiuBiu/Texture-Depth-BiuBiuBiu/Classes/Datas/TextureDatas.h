//
//  TextureDatas.h
//  Texture-Base-OneStep
//
//  Created by Windy on 2017/2/14.
//  Copyright © 2017年 Windy. All rights reserved.
//

#ifndef TextureDatas_h
#define TextureDatas_h

#import <OpenGLES/gltypes.h>

typedef struct {
    GLfloat position[3];
    GLfloat texCoord[2];
    GLfloat normalCoord[3];
}VYVertex;

// MARK: Square

static const VYVertex tex2DSquareDatas[] = {
    {{-1.0, -1.0, 0.0}, {0.0, 0.0}},
    {{ 1.0, -1.0, 0.0}, {1.0, 0.0}},
    {{ 1.0,  1.0, 0.0}, {1.0, 1.0}},
    {{-1.0,  1.0, 0.0}, {0.0, 1.0}},
};

static const GLubyte squareIndices[] = {
    0, 1, 2,
    2, 3, 0,
};

// 2 * 2
static const GLfloat tex2DPixelDatas[3*4] = {
    1.000, 1.000, 0.108,//[UIColor colorWithRed:1.000 green:1.000 blue:0.108 alpha:1.000]
    0.458, 1.000, 0.404,//[UIColor colorWithRed:0.458 green:1.000 blue:0.404 alpha:1.000]
    0.458, 1.000, 0.770,//[UIColor colorWithRed:0.458 green:1.000 blue:0.770 alpha:1.000]
    0.729, 0.350, 0.770,//[UIColor colorWithRed:0.729 green:0.350 blue:0.770 alpha:1.000]
};
// (2 * 2 * 6)
static const GLfloat texCubemapPixelDatas[6][3*4] = {
    1.000, 1.000, 0.108,//[UIColor colorWithRed:1.000 green:1.000 blue:0.108 alpha:1.000]
    0.458, 1.000, 0.404,//[UIColor colorWithRed:0.458 green:1.000 blue:0.404 alpha:1.000]
    0.458, 1.000, 0.770,//[UIColor colorWithRed:0.458 green:1.000 blue:0.770 alpha:1.000]
    0.729, 0.350, 0.770,//[UIColor colorWithRed:0.729 green:0.350 blue:0.770 alpha:1.000]
    
    0.145, 0.319, 0.308,//[UIColor colorWithRed:0.145 green:0.319 blue:0.308 alpha:1.000]
    0.732, 0.319, 0.308,//[UIColor colorWithRed:0.732 green:0.319 blue:0.308 alpha:1.000]
    0.732, 0.727, 0.308,//[UIColor colorWithRed:0.732 green:0.727 blue:0.308 alpha:1.000]
    0.732, 0.727, 0.889,//[UIColor colorWithRed:0.732 green:0.727 blue:0.889 alpha:1.000]
    
    0.633, 0.820, 0.058,//[UIColor colorWithRed:0.633 green:0.820 blue:0.058 alpha:1.000]
    0.936, 0.820, 0.994,//[UIColor colorWithRed:0.936 green:0.820 blue:0.994 alpha:1.000]
    0.017, 0.029, 0.994,//[UIColor colorWithRed:0.017 green:0.029 blue:0.994 alpha:1.000]
    0.000, 0.000, 0.000,//[UIColor colorWithWhite:0.000 alpha:1.000]
    
    0.593, 0.854, 0.000,//[UIColor colorWithRed:0.593 green:0.854 blue:0.000 alpha:1.000]
    0.593, 0.337, 0.000,//[UIColor colorWithRed:0.593 green:0.337 blue:0.000 alpha:1.000]
    1.000, 0.407, 0.709,//[UIColor colorWithRed:1.000 green:0.407 blue:0.709 alpha:1.000]
    0.337, 0.407, 0.709,//[UIColor colorWithRed:0.337 green:0.407 blue:0.709 alpha:1.000]
    
    0.337, 0.738, 0.709,//[UIColor colorWithRed:0.337 green:0.738 blue:0.709 alpha:1.000]
    0.337, 0.994, 0.709,//[UIColor colorWithRed:0.337 green:0.994 blue:0.709 alpha:1.000]
    0.186, 0.105, 0.290,//[UIColor colorWithRed:0.186 green:0.105 blue:0.290 alpha:1.000]
    0.633, 0.872, 0.500,//[UIColor colorWithRed:0.633 green:0.872 blue:0.500 alpha:1.000]
    
    0.290, 0.924, 0.680,//[UIColor colorWithRed:0.290 green:0.924 blue:0.680 alpha:1.000]
    0.290, 0.924, 0.174,//[UIColor colorWithRed:0.290 green:0.924 blue:0.174 alpha:1.000]
    0.982, 0.163, 0.174,//[UIColor colorWithRed:0.982 green:0.163 blue:0.174 alpha:1.000]
    0.628, 0.970, 0.878,//[UIColor colorWithRed:0.628 green:0.970 blue:0.878 alpha:1.000]
};

// MARK: Cube

static const VYVertex tex2DCubeDatas[] = {
    
    // 如果打开 glEnable(GL_CULL_FACE);
    // 就会有三个面不被渲染，即消失了；
    // 出现这种情况的原因是，时钟方向的问题，而 GL_CULL_FACE
    // 就是把看不见的取消渲染，所以也就消失了半数的面了；
    // 结果就是，要么 Front + Left + Top 有；要么 Back + Right + Bottom 有；
    // 下面的数据源中[时钟方向--> 如：3D 空间中下面的数据源， 0-1-2-3 与 4-5-6-7]，
    // Back = !Front; Left = !Right; [Top = Bottom]-->错误就在这;
    // 如果要使用这个数据源，就要 关闭 glEnable(GL_CULL_FACE);
//    // Front [Front 的 z 是正的]
//    {{-1.0, -1.0,  1.0}, {0.0, 0.0}}, // 0
//    {{ 1.0, -1.0,  1.0}, {1.0, 0.0}}, // 1
//    {{ 1.0,  1.0,  1.0}, {1.0, 1.0}}, // 2
//    {{-1.0,  1.0,  1.0}, {0.0, 1.0}}, // 3
//    // Back [Back 的 z 是负的]
//    {{-1.0,  1.0, -1.0}, {0.0, 0.0}}, //4[3: -Z]
//    {{ 1.0,  1.0, -1.0}, {1.0, 0.0}}, //5[2: -Z]
//    {{ 1.0, -1.0, -1.0}, {1.0, 1.0}}, //6[1: -Z]
//    {{-1.0, -1.0, -1.0}, {0.0, 1.0}}, //7[0: -Z]
//    // Left [Left 的 x 是负的]
//    {{-1.0, -1.0,  1.0}, {0.0, 0.0}}, //8[0]
//    {{-1.0,  1.0,  1.0}, {1.0, 0.0}}, //9[3]
//    {{-1.0,  1.0, -1.0}, {1.0, 1.0}}, //10[4]
//    {{-1.0, -1.0, -1.0}, {0.0, 1.0}}, //11[7]
//    // Right [Right 的 x 是正的]
//    {{ 1.0, -1.0,  1.0}, {0.0, 0.0}}, //12[1]
//    {{ 1.0, -1.0, -1.0}, {1.0, 0.0}}, //13[6]
//    {{ 1.0,  1.0, -1.0}, {1.0, 1.0}}, //14[5]
//    {{ 1.0,  1.0,  1.0}, {0.0, 1.0}}, //15[2]
//    // Top [Top 的 y 是正的]
//    {{-1.0,  1.0,  1.0}, {0.0, 0.0}}, //16[3]
//    {{ 1.0,  1.0,  1.0}, {1.0, 0.0}}, //17[2]
//    {{ 1.0,  1.0, -1.0}, {1.0, 1.0}}, //18[5]
//    {{-1.0,  1.0, -1.0}, {0.0, 1.0}}, //19[4]
//    // Bottom [Bottom 的 y 是负的]
//    {{-1.0, -1.0,  1.0}, {0.0, 0.0}}, //20[0]
//    {{ 1.0, -1.0,  1.0}, {1.0, 0.0}}, //21[1]
//    {{ 1.0, -1.0, -1.0}, {1.0, 1.0}}, //22[6]
//    {{-1.0, -1.0, -1.0}, {0.0, 1.0}}, //23[7]
    
    // 为了使渲染更有效，选择打开 GL_CULL_FACE
    // 打开 glEnable(GL_CULL_FACE); 不会出现问题；
    // 上面的数据源中[时钟方向]，Back = Front; Left = Right; Top = Bottom;
    // 那么如果要使用 GL_CULL_FACE 就是要，在背面的面的时钟方向与前面的面的时钟方向相反，
    // 即相当于，背面的面可以被“看到”
    // 即结果，要求数据源时钟方向是：Back = !Fornt; Left = !Right; Top = !Bottom;
    // Front [Front 的 z 是正的]
    {{-1.0, -1.0,  1.0}, {0.0, 0.0}}, // 0
    {{ 1.0, -1.0,  1.0}, {1.0, 0.0}}, // 1
    {{ 1.0,  1.0,  1.0}, {1.0, 1.0}}, // 2
    {{-1.0,  1.0,  1.0}, {0.0, 1.0}}, // 3
    // Back [Back 的 z 是负的]
    {{-1.0,  1.0, -1.0}, {0.0, 0.0}}, //4[3: -Z]
    {{ 1.0,  1.0, -1.0}, {1.0, 0.0}}, //5[2: -Z]
    {{ 1.0, -1.0, -1.0}, {1.0, 1.0}}, //6[1: -Z]
    {{-1.0, -1.0, -1.0}, {0.0, 1.0}}, //7[0: -Z]
    // Left [Left 的 x 是负的]
    {{-1.0, -1.0,  1.0}, {0.0, 0.0}}, //8[0]
    {{-1.0,  1.0,  1.0}, {1.0, 0.0}}, //9[3]
    {{-1.0,  1.0, -1.0}, {1.0, 1.0}}, //10[4]
    {{-1.0, -1.0, -1.0}, {0.0, 1.0}}, //11[7]
    // Right [Right 的 x 是正的]
    {{ 1.0, -1.0,  1.0}, {0.0, 0.0}}, //12[1]
    {{ 1.0, -1.0, -1.0}, {1.0, 0.0}}, //13[6]
    {{ 1.0,  1.0, -1.0}, {1.0, 1.0}}, //14[5]
    {{ 1.0,  1.0,  1.0}, {0.0, 1.0}}, //15[2]
    // Top [Top 的 y 是正的]
    {{-1.0,  1.0,  1.0}, {0.0, 0.0}}, //16[3]
    {{ 1.0,  1.0,  1.0}, {1.0, 0.0}}, //17[2]
    {{ 1.0,  1.0, -1.0}, {1.0, 1.0}}, //18[5]
    {{-1.0,  1.0, -1.0}, {0.0, 1.0}}, //19[4]
    // Bottom [Bottom 的 y 是负的]
    {{-1.0, -1.0,  1.0}, {0.0, 0.0}}, //20[0]
    {{-1.0, -1.0, -1.0}, {1.0, 0.0}}, //21[7]
    {{ 1.0, -1.0, -1.0}, {1.0, 1.0}}, //22[6]
    {{ 1.0, -1.0,  1.0}, {0.0, 1.0}}, //23[1]
    
};

static const VYVertex tex2DElongatedUDCubeDatas[] = {
    
    // Front [Front 的 z 是正的]
    {{-1.0, -1.0,  1.0}, {0.000, 0.000}}, // 0
    {{ 1.0, -1.0,  1.0}, {0.333, 0.000}}, // 1
    {{ 1.0,  1.0,  1.0}, {0.333, 0.500}}, // 2
    {{-1.0,  1.0,  1.0}, {0.000, 0.500}}, // 3
    // Back [Back 的 z 是负的]
    {{-1.0,  1.0, -1.0}, {0.000, 0.500}}, //4[3: -Z]
    {{ 1.0,  1.0, -1.0}, {0.333, 0.500}}, //5[2: -Z]
    {{ 1.0, -1.0, -1.0}, {0.333, 1.000}}, //6[1: -Z]
    {{-1.0, -1.0, -1.0}, {0.000, 1.000}}, //7[0: -Z]
    // Left [Left 的 x 是负的]
    {{-1.0, -1.0,  1.0}, {0.333, 0.000}}, //8[0]
    {{-1.0,  1.0,  1.0}, {0.666, 0.000}}, //9[3]
    {{-1.0,  1.0, -1.0}, {0.666, 0.500}}, //10[4]
    {{-1.0, -1.0, -1.0}, {0.333, 0.500}}, //11[7]
    // Right [Right 的 x 是正的]
    {{ 1.0, -1.0,  1.0}, {0.333, 0.500}}, //12[1]
    {{ 1.0, -1.0, -1.0}, {1.666, 0.500}}, //13[6]
    {{ 1.0,  1.0, -1.0}, {1.666, 1.000}}, //14[5]
    {{ 1.0,  1.0,  1.0}, {0.333, 1.000}}, //15[2]
    // Top [Top 的 y 是正的]
    {{-1.0,  1.0,  1.0}, {0.666, 0.000}}, //16[3]
    {{ 1.0,  1.0,  1.0}, {1.000, 0.000}}, //17[2]
    {{ 1.0,  1.0, -1.0}, {1.000, 0.500}}, //18[5]
    {{-1.0,  1.0, -1.0}, {0.666, 0.500}}, //19[4]
    // Bottom [Bottom 的 y 是负的]
    {{-1.0, -1.0,  1.0}, {0.666, 0.500}}, //20[0]
    {{-1.0, -1.0, -1.0}, {1.000, 0.500}}, //21[7]
    {{ 1.0, -1.0, -1.0}, {1.000, 1.000}}, //22[6]
    {{ 1.0, -1.0,  1.0}, {0.666, 1.000}}, //23[1]
    
};

static const VYVertex tex2DElongatedDDCubeDatas[] = {
    
    // Front [Front 的 z 是正的]
    {{-1.0, -1.0,  1.0}, {0.000, 0.000}}, // 0
    {{ 1.0, -1.0,  1.0}, {0.250, 0.000}}, // 1
    {{ 1.0,  1.0,  1.0}, {0.250, 0.500}}, // 2
    {{-1.0,  1.0,  1.0}, {0.000, 0.500}}, // 3
    // Back [Back 的 z 是负的]
    {{-1.0,  1.0, -1.0}, {0.000, 0.500}}, //4[3: -Z]
    {{ 1.0,  1.0, -1.0}, {0.250, 0.500}}, //5[2: -Z]
    {{ 1.0, -1.0, -1.0}, {0.250, 1.000}}, //6[1: -Z]
    {{-1.0, -1.0, -1.0}, {0.000, 1.000}}, //7[0: -Z]
    // Left [Left 的 x 是负的]
    {{-1.0, -1.0,  1.0}, {0.250, 0.000}}, //8[0]
    {{-1.0,  1.0,  1.0}, {0.500, 0.000}}, //9[3]
    {{-1.0,  1.0, -1.0}, {0.500, 0.500}}, //10[4]
    {{-1.0, -1.0, -1.0}, {0.250, 0.500}}, //11[7]
    // Right [Right 的 x 是正的]
    {{ 1.0, -1.0,  1.0}, {0.250, 0.500}}, //12[1]
    {{ 1.0, -1.0, -1.0}, {0.500, 0.500}}, //13[6]
    {{ 1.0,  1.0, -1.0}, {0.500, 1.000}}, //14[5]
    {{ 1.0,  1.0,  1.0}, {0.250, 1.000}}, //15[2]
    // Top [Top 的 y 是正的]
    {{-1.0,  1.0,  1.0}, {0.500, 0.000}}, //16[3]
    {{ 1.0,  1.0,  1.0}, {0.750, 0.000}}, //17[2]
    {{ 1.0,  1.0, -1.0}, {0.750, 0.500}}, //18[5]
    {{-1.0,  1.0, -1.0}, {0.500, 0.500}}, //19[4]
    // Bottom [Bottom 的 y 是负的]
    {{-1.0, -1.0,  1.0}, {0.750, 0.000}}, //20[0]
    {{-1.0, -1.0, -1.0}, {1.000, 0.000}}, //21[7]
    {{ 1.0, -1.0, -1.0}, {1.000, 0.500}}, //22[6]
    {{ 1.0, -1.0,  1.0}, {0.750, 0.500}}, //23[1]
    
};

static const VYVertex texCubemapCubeDatas[] = {
    
    // Front [Front 的 z 是正的]
    {{-1.0, -1.0,  1.0}, {}, {-1.0, -1.0,  1.0}}, // 0
    {{ 1.0, -1.0,  1.0}, {}, { 1.0, -1.0,  1.0}}, // 1
    {{ 1.0,  1.0,  1.0}, {}, { 1.0,  1.0,  1.0}}, // 2
    {{-1.0,  1.0,  1.0}, {}, {-1.0,  1.0,  1.0}}, // 3
    // Back [Back 的 z 是负的]
    {{-1.0,  1.0, -1.0}, {}, {-1.0,  1.0, -1.0}}, //4[3: -Z]
    {{ 1.0,  1.0, -1.0}, {}, { 1.0,  1.0, -1.0}}, //5[2: -Z]
    {{ 1.0, -1.0, -1.0}, {}, { 1.0, -1.0, -1.0}}, //6[1: -Z]
    {{-1.0, -1.0, -1.0}, {}, {-1.0, -1.0, -1.0}}, //7[0: -Z]
    // Left [Left 的 x 是负的]
    {{-1.0, -1.0,  1.0}, {}, {-1.0, -1.0,  1.0}}, //8[0]
    {{-1.0,  1.0,  1.0}, {}, {-1.0,  1.0,  1.0}}, //9[3]
    {{-1.0,  1.0, -1.0}, {}, {-1.0,  1.0, -1.0}}, //10[4]
    {{-1.0, -1.0, -1.0}, {}, {-1.0, -1.0, -1.0}}, //11[7]
    // Right [Right 的 x 是正的]
    {{ 1.0, -1.0,  1.0}, {}, { 1.0, -1.0,  1.0}}, //12[1]
    {{ 1.0, -1.0, -1.0}, {}, { 1.0, -1.0, -1.0}}, //13[6]
    {{ 1.0,  1.0, -1.0}, {}, { 1.0,  1.0, -1.0}}, //14[5]
    {{ 1.0,  1.0,  1.0}, {}, { 1.0,  1.0,  1.0}}, //15[2]
    // Top [Top 的 y 是正的]
    {{-1.0,  1.0,  1.0}, {}, {-1.0,  1.0,  1.0}}, //16[3]
    {{ 1.0,  1.0,  1.0}, {}, { 1.0,  1.0,  1.0}}, //17[2]
    {{ 1.0,  1.0, -1.0}, {}, { 1.0,  1.0, -1.0}}, //18[5]
    {{-1.0,  1.0, -1.0}, {}, {-1.0,  1.0, -1.0}}, //19[4]
    // Bottom [Bottom 的 y 是负的]
    {{-1.0, -1.0,  1.0}, {}, {-1.0, -1.0,  1.0}}, //20[0]
    {{-1.0, -1.0, -1.0}, {}, { 1.0, -1.0,  1.0}}, //21[7]
    {{ 1.0, -1.0, -1.0}, {}, { 1.0, -1.0, -1.0}}, //22[6]
    {{ 1.0, -1.0,  1.0}, {}, {-1.0, -1.0, -1.0}}, //23[1]
    
};

static const GLubyte texCubeIndices[] = {
    //Front
    0, 1, 2,
    2, 3, 0,
    //Right
    4, 5, 6,
    6, 7, 4,
    //Back
    8, 9, 10,
    10, 11, 8,
    //Left
    12, 13, 14,
    14, 15, 12,
    //Top
    16, 17, 18,
    18, 19, 16,
    //Bottom
    20, 21, 22,
    22, 23, 20,
};

#endif /* TextureDatas_h */
