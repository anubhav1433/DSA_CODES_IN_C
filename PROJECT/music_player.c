#include "queue.h"
#include "dll.h"
#include "music_player.h"
#include <stdio.h>
#include <stdlib.h>

playlist_t *create_playlist() // return a newly created doubly linked list
{
	// DO NOT MODIFY!!!
	playlist_t *playlist = (playlist_t *)malloc(sizeof(playlist_t));
	playlist->list = create_list();
	playlist->num_songs = 0;
	playlist->last_song = NULL;
	return playlist;
}

void delete_playlist(playlist_t *playlist) // delete the playlist
{
	// DO NOT MODIFY!!!
	delete_list(playlist->list);
	free(playlist);
}

music_queue_t *create_music_queue() // return a newly created queue
{
	// DO NOT MODIFY!!!
	return create_queue();
}

void clear_music_queue(music_queue_t *q) // clear the queue q
{
	// DO NOT MODIFY!!!
	delete_queue(q);
}

void add_song(playlist_t *playlist, int song_id, int where) // TODO: add a song id to the end of the playlist
{
	node_t *temp = (node_t *)malloc(sizeof(node_t));
	temp->data = song_id;
	temp->next = NULL;
	temp->prev = NULL;
	if (where == -1)
	{
		insert_front(playlist->list, song_id);
	}
	if (where == -2)
	{
		insert_back(playlist->list, song_id);
	}
	if (where >= 0)
	{
		insert_after(playlist->list, song_id, where);
	}
	playlist->num_songs++;
	return;
}

void delete_song(playlist_t *playlist, int song_id) // TODO: remove song id from the playlist
{
	delete_node(playlist->list, song_id);
	playlist->num_songs--;
}

song_t *search_song(playlist_t *playlist, int song_id) // TODO: return a pointer to the node where the song id is present in the playlist
{
	return search(playlist->list, song_id);
}

void search_and_play(playlist_t *playlist, int song_id) // TODO: play the song with given song_id from the list(no need to bother about the queue. Call to this function should always play the given song and further calls to play_next and play_previous)
{
	node_t *temp = search_song(playlist, song_id);
	if (temp == NULL)
	{
		return;
	}
	else
	{
		play_song(temp->data);
		playlist->last_song = temp;
	}
}

void play_next(playlist_t *playlist, music_queue_t *q) // TODO: play the next song in the linked list if the queue is empty. If the queue if not empty, play from the queue
{
	if (!empty(q))
	{
		play_from_queue(q);
		return;
	}
	if (playlist->last_song == NULL || playlist->last_song == playlist->list->tail)
	{
		play_song(playlist->list->head->data);
		playlist->last_song = playlist->list->head;
		return;
	}
	play_song(playlist->last_song->next->data);
	playlist->last_song = playlist->last_song->next;
}

void play_previous(playlist_t *playlist) // TODO: play the previous song from the linked list
{
	if (playlist->last_song == playlist->list->head)
	{
		play_song(playlist->list->tail->data);
		playlist->last_song = playlist->list->tail;
		return;
	}
	play_song(playlist->last_song->prev->data);
	playlist->last_song = playlist->last_song->prev;
}

void play_from_queue(music_queue_t *q) // TODO: play a song from the queue
{
	node_t *temp = q->front;
	play_song(temp->data);
	dequeue(q);
	return;
}

void insert_to_queue(music_queue_t *q, int song_id) // TODO: insert a song id to the queue
{
	enqueue(q, song_id);
}

void reverse(playlist_t *playlist) // TODO: reverse the order of the songs in the given playlist. (Swap the nodes, not data)
{
	song_t *cur = playlist->list->tail, *prev;
	while (cur != NULL)
	{
		prev = cur->next;
		cur->next = cur->prev;
		cur->prev = prev;
		cur = cur->next;
	}
	prev = playlist->list->tail;
	playlist->list->tail = playlist->list->head;
	playlist->list->head = prev;
}

void k_swap(playlist_t *playlist, int k) // TODO: swap the node at position i with node at position i+k upto the point where i+k is less than the size of the linked list
{
	if (k == 0)
	{
		return;
	}
	else if (k == 1)
	{
		playlist->list->tail->next = playlist->list->head;
		playlist->list->head = playlist->list->head->next;
		playlist->list->head->prev = NULL;
		playlist->list->tail->next->prev = playlist->list->tail;
		playlist->list->tail = playlist->list->tail->next;
		playlist->list->tail->next = NULL;
	}
	else
	{
		song_t *temp = playlist->list->head;
		song_t *temp2 = playlist->list->head;
		song_t *temp_p = NULL, *temp_n = NULL;
		for (int i = 0; i < k; i++)
		{
			temp2 = temp2->next;
		}
		for (int i = 0; i < playlist->num_songs - k; i++)
		{
			temp_n = temp->next;
			temp_p = temp2->prev;
			if (temp == playlist->list->head)
			{
				playlist->list->head = temp2;
				temp2->prev = NULL;
			}
			else
			{
				temp2->prev = temp->prev;
				temp2->prev->next = temp2;
			}
			if (temp2 == playlist->list->tail)
			{
				playlist->list->tail = temp;
				temp->next = NULL;
			}
			else
			{
				temp->next = temp2->next;
				temp->next->prev = temp;
			}
			temp->prev = temp_p;
			temp_p->next = temp;
			temp2->next = temp_n;
			temp_n->prev = temp2;
			temp2 = temp->next;
			temp = temp_n;
		}
		temp = temp2 = temp_n = temp_p = NULL;
	}
}

void shuffle(playlist_t *playlist, int k) // TODO: perform k_swap and reverse
{
	k_swap(playlist, k);
	reverse(playlist);
}

song_t *debug(playlist_t *playlist) // TODO: if the given linked list has a cycle, return the start of the cycle, else return null. Check cycles only in forward direction i.e with the next pointer. No need to check for cycles in the backward pointer.
{
	return playlist->list->tail->next;
}

void display_playlist(playlist_t *p) // Displays the playlist
{
	// DO NOT MODIFY!!!
	display_list(p->list);
}

void play_song(int song_id)
{
	// DO NOT MODIFY!!!
	printf("Playing: %d\n", song_id);
}