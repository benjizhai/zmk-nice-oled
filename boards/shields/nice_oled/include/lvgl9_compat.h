#pragma once

/*
 * LVGL 8 -> 9 compatibility shims.
 *
 * Provides backward-compatible #defines so existing code using the
 * LVGL 8.x naming conventions compiles against LVGL 9.x.
 */

/* Type renames */
#define lv_img_dsc_t            lv_image_dsc_t
#define lv_draw_img_dsc_t       lv_draw_image_dsc_t

/* Function renames */
#define lv_img_create           lv_image_create
#define lv_img_set_src          lv_image_set_src
#define lv_draw_img_dsc_init    lv_draw_image_dsc_init

/* Macro renames */
#define LV_IMG_DECLARE          LV_IMAGE_DECLARE
#define LV_IMG_CF_TRUE_COLOR    LV_COLOR_FORMAT_NATIVE
#define LV_IMG_CF_INDEXED_1BIT  LV_COLOR_FORMAT_I1
#define LV_IMG_ZOOM_NONE        LV_SCALE_NONE

/* Removed types */
#define lv_coord_t              int32_t

/* Object API renames */
#define lv_obj_del              lv_obj_delete

/* Text API rename */
#define lv_txt_get_size         lv_text_get_size
