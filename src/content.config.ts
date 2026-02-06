import { defineCollection } from 'astro:content';
import { z } from 'zod';

const postCollection = defineCollection({
    schema: z.object({
        title: z.string(),
        tag: z.string(),
        pubDate: z.coerce.date(),
        description: z.string(),
        author: z.string(),
        draft: z.boolean().optional().default(false),
    }),
})

export const collections = {posts: postCollection}