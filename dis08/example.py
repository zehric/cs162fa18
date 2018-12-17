# In this example, we want to find an episode in our library (unique ID)
# when given an episode number to look for

library = [()] * 22 # 22 total episodes, all empty

library_size = 0
# We don't need to keep track of episode number because the index is always the
# episode number subtracted by 1
# Thus, each episode in our library is a tuple of (ID, name)
def add_to_library(ep_num, name):
    global library_size
    library[ep_num - 1] = (library_size, name) # set ID to current size
    library_size += 1                          # increment size

# Four different episodes in our library
add_to_library(5, "The Truth of Classics Club and its History")
add_to_library(10, "What No One Noticed")
add_to_library(11, "End Credits of The Fool")
add_to_library(17, "Are the Mountains Sunny?")

# Now let's say we want to find perform a lookup for episode 11.
# How do we find the corresponding episode id (2)?
print("normal library:")

LOOKUP_EP_NUM = 17

episode = library[LOOKUP_EP_NUM - 1]
print("(id, name) =", episode) # should be 3

# But we can also iterate through our library and find the 10th episode
# directly (naive for loop)

for i in range(len(library)):
    if i == LOOKUP_EP_NUM - 1:
        episode = library[i]
        break

print("(id, name) =", episode) # should be 2

# Taking this idea a step further, we can compress our library
# Now our library is composed of tuples of (episode number, episode name)
# And the index is the episode ID
library = []
library.append((5, "The Truth of Classics Club and Its History"))
library.append((10, "What No One Noticed"))
library.append((11, "End Credits of The Fool"))
library.append((17, "Are the Mountains Sunny?"))

print("inverted library:")

# We can lookup by just iterating through our inverted library
# This time our episode id is just the index
for i in range(len(library)):
    episode_num, episode_name = library[i]
    if episode_num == LOOKUP_EP_NUM:
        print("(id, name) =", (i, episode_name))
        break

# How does this relate to page tables?
# Episode number <=> virtual page number (the thing we're using for lookup)
# Episode ID <=> physical page number (the thing we're trying to find)
# Episode name <=> offset and other valid bits (data in each entry)
# The "inverted library" is similar to an inverted page table
