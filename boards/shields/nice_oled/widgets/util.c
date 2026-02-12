#include "util.h"
#include <ctype.h>
#include <zephyr/kernel.h>

void to_uppercase(char *str) {
  for (int i = 0; str[i] != '\0'; i++) {
    str[i] = toupper(str[i]);
  }
}

void rotate_canvas(lv_obj_t *canvas, lv_color_t cbuf[]) {
  static lv_color_t cbuf_tmp[CANVAS_HEIGHT * CANVAS_HEIGHT];
  memcpy(cbuf_tmp, cbuf, sizeof(cbuf_tmp));

  lv_img_dsc_t img = {
    .header = {
      .magic = LV_IMAGE_HEADER_MAGIC,
      .cf = LV_IMG_CF_TRUE_COLOR,
      .w = CANVAS_HEIGHT,
      .h = CANVAS_HEIGHT,
      .stride = CANVAS_HEIGHT * sizeof(lv_color_t),
    },
    .data_size = sizeof(cbuf_tmp),
    .data = (const uint8_t *)cbuf_tmp,
  };

  lv_canvas_fill_bg(canvas, LVGL_BACKGROUND, LV_OPA_COVER);

  lv_layer_t layer;
  lv_canvas_init_layer(canvas, &layer);

  lv_draw_image_dsc_t d;
  lv_draw_image_dsc_init(&d);
  d.src = &img;
  d.rotation = 900;
  d.pivot.x = CANVAS_HEIGHT / 2;
  d.pivot.y = CANVAS_HEIGHT / 2;

  lv_area_t area = {0, 0, CANVAS_HEIGHT - 1, CANVAS_HEIGHT - 1};
  lv_draw_image(&layer, &d, &area);

  lv_canvas_finish_layer(canvas, &layer);
}

void draw_background(lv_layer_t *layer) {
  lv_draw_rect_dsc_t rect_black_dsc;
  init_rect_dsc(&rect_black_dsc, LVGL_BACKGROUND);

  lv_area_t area = {0, 0, CANVAS_WIDTH - 1, CANVAS_HEIGHT - 1};
  lv_draw_rect(layer, &rect_black_dsc, &area);
}

void init_label_dsc(lv_draw_label_dsc_t *label_dsc, lv_color_t color,
                    const lv_font_t *font, lv_text_align_t align) {
  lv_draw_label_dsc_init(label_dsc);
  label_dsc->color = color;
  label_dsc->font = font;
  label_dsc->align = align;
}

void init_rect_dsc(lv_draw_rect_dsc_t *rect_dsc, lv_color_t bg_color) {
  lv_draw_rect_dsc_init(rect_dsc);
  rect_dsc->bg_color = bg_color;
}

void init_line_dsc(lv_draw_line_dsc_t *line_dsc, lv_color_t color,
                   uint8_t width) {
  lv_draw_line_dsc_init(line_dsc);
  line_dsc->color = color;
  line_dsc->width = width;
}
