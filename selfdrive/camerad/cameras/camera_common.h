#ifndef CAMERA_COMMON_H
#define CAMERA_COMMON_H

#include <stdint.h>
#include <stdbool.h>

#include "common/visionipc.h"

#define CAMERA_ID_IMX298 0
#define CAMERA_ID_IMX179 1
#define CAMERA_ID_S5K3P8SP 2
#define CAMERA_ID_OV8865 3
#define CAMERA_ID_IMX298_FLIPPED 4
#define CAMERA_ID_OV10640 5
#define CAMERA_ID_LGC920 6
#define CAMERA_ID_LGC615 7
#define CAMERA_ID_AR0231 8
#define CAMERA_ID_MAX 9

#define LOG_CAMERA_ID_FCAMERA 0
#define LOG_CAMERA_ID_DCAMERA 1
#define LOG_CAMERA_ID_ECAMERA 2
#define LOG_CAMERA_ID_QCAMERA 3
#define LOG_CAMERA_ID_MAX 4

#ifdef __cplusplus
extern "C" {
#endif

typedef struct CameraInfo {
  const char* name;
  int frame_width, frame_height;
  int frame_stride;
  bool bayer;
  int bayer_flip;
  bool hdr;
} CameraInfo;

typedef struct LogCameraInfo {
  const char* filename;
  const char* frame_packet_name;
  const char* encode_idx_name;
  VisionStreamType stream_type;
  int frame_width, frame_height;
  int fps;
  int bitrate;
  bool is_h265;
  bool downscale;
  bool has_qcamera;
} LogCameraInfo;

typedef struct FrameMetadata {
  uint32_t frame_id;
  uint64_t timestamp_eof;
  unsigned int frame_length;
  unsigned int integ_lines;
  unsigned int global_gain;
  unsigned int lens_pos;
  float lens_sag;
  float lens_err;
  float lens_true_pos;
  float gain_frac;
} FrameMetadata;

extern CameraInfo cameras_supported[CAMERA_ID_MAX];

#ifdef __cplusplus
}
#endif

#endif