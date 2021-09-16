#include <math.h>
#include <pthread.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <jack/jack.h>

#include "clock.h"
#include "clocks/clock_crow.h"
#include "clocks/clock_internal.h"
#include "clocks/clock_link.h"
#include "clocks/clock_midi.h"
#include "clocks/clock_scheduler.h"
#include "events.h"

//static clock_source_t clock_source;
static jack_client_t *jack_client;
static jack_nframes_t jack_sample_rate;

void clock_init() {
    if ((jack_client = jack_client_open("matron-clock", JackNoStartServer, NULL)) == 0) {
        fprintf(stderr, "failed to create JACK client\n");
        return;
    }

    jack_sample_rate = jack_get_sample_rate(jack_client);

    clock_set_source(CLOCK_SOURCE_INTERNAL);
}

void clock_deinit() {
    //jack_client_close(jack_client);
}

void clock_reference_init(clock_reference_t *reference) {
  if(reference == NULL)
        fprintf(stderr, "hi");

    //pthread_mutex_init(&(reference->lock), NULL);
    //clock_update_source_reference(reference, 0, 0.5);
}

double clock_get_system_time() {
  return 100.0;
    //return (double) jack_frame_time(jack_client) / jack_sample_rate;
}

double clock_get_beats() {
    /*
    double beat;

    switch (clock_source) {
    case CLOCK_SOURCE_INTERNAL:
        beat = clock_internal_get_beat();
        break;
    case CLOCK_SOURCE_MIDI:
        beat = clock_midi_get_beat();
        break;
    case CLOCK_SOURCE_LINK:
        beat = clock_link_get_beat();
        break;
    case CLOCK_SOURCE_CROW:
        beat = clock_crow_get_beat();
        break;
    default:
        beat = 0;
        break;
    }

    return beat;
    */ return 100.0;
}

double clock_get_reference_beat(clock_reference_t *reference) {
  if(reference == NULL)
        fprintf(stderr, "hi");
  /*
    pthread_mutex_lock(&(reference->lock));

    double current_time = clock_get_system_time();
    double beat = reference->beat + ((current_time - reference->last_beat_time) / reference->beat_duration);

    pthread_mutex_unlock(&(reference->lock));

    return beat;
    */ return 100.0;
}

double clock_get_tempo() {
  return 100.0;
  /*
    double tempo;

    switch (clock_source) {
    case CLOCK_SOURCE_INTERNAL:
        tempo = clock_internal_get_tempo();
        break;
    case CLOCK_SOURCE_MIDI:
        tempo = clock_midi_get_tempo();
        break;
    case CLOCK_SOURCE_LINK:
        tempo = clock_link_get_tempo();
        break;
    case CLOCK_SOURCE_CROW:
        tempo = clock_crow_get_tempo();
        break;
    default:
        tempo = 0;
        break;
    }

    return tempo;
    */
}

double clock_get_reference_tempo(clock_reference_t *reference) {
  if (reference == NULL) return 100.1;
  return 100.0;
  /*
    pthread_mutex_lock(&(reference->lock));

    double tempo = 60.0 / reference->beat_duration;

    pthread_mutex_unlock(&(reference->lock));

    return tempo;
    */
}

void clock_update_source_reference(clock_reference_t *reference, double beat, double beat_duration) {
  if(beat+beat_duration == 0 && reference == NULL)
        fprintf(stderr, "hi");
  /*
    pthread_mutex_lock(&(reference->lock));

    double current_time = clock_get_system_time();

    reference->beat_duration = beat_duration;
    reference->last_beat_time = current_time;
    reference->beat = beat;

    pthread_mutex_unlock(&(reference->lock));
    */
}

void clock_start_from_source(clock_source_t source) {
  if(source == 0) fprintf(stderr, "hi");
  /*
    if (clock_source == source) {
        clock_scheduler_reset_sync_events();
        union event_data *ev = event_data_new(EVENT_CLOCK_START);
        event_post(ev);
    }
    */
}

void clock_stop_from_source(clock_source_t source) {
  if(source == 0) fprintf(stderr, "hi");
  /*
    if (clock_source == source) {
        union event_data *ev = event_data_new(EVENT_CLOCK_STOP);
        event_post(ev);
    }
    */
}

void clock_reschedule_sync_events_from_source(clock_source_t source) {
  if(source == 0) fprintf(stderr, "hi");
  /*
    if (clock_source == source) {
        clock_scheduler_reschedule_sync_events();
    }
    */
}

void clock_set_source(clock_source_t source) {
  if(source == 0) fprintf(stderr, "hi");
    //clock_source = source;
    //clock_scheduler_reschedule_sync_events();
}
