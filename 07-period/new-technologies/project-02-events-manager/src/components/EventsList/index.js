import { FlatList, useWindowDimensions, View } from "react-native";
import { EventCard } from "../EventCard";
import { styles } from "./styles";

export function EventsList({
  emptyText,
  containerStyle,
  events = [],
  horizontal = false,
  showEditAction = false,
}) {
  const { width } = useWindowDimensions();
  const eventWidth = width / 1.5;

  if (!horizontal || events.length === 0) {
    return (
      <View style={[styles.contentContainer, containerStyle]}>
        {events.length > 0 ? (
          events.map((event) => (
            <EventCard
              key={event.id}
              event={event}
              showEditAction={showEditAction}
            />
          ))
        ) : (
          <EventCard.Empty text={emptyText} />
        )}
      </View>
    );
  }

  return (
    <FlatList
      style={[styles.container, styles.horizontal, containerStyle]}
      contentContainerStyle={styles.contentContainer}
      data={events}
      keyExtractor={(item) => item.id}
      renderItem={({ item }) => (
        <EventCard
          containerStyle={{ width: eventWidth }}
          event={item}
          showEditAction={showEditAction}
        />
      )}
      snapToAlignment="start"
      snapToOffsets={events.map(
        (_, index) => index * (eventWidth + styles.contentContainer.gap)
      )}
      decelerationRate="fast"
      horizontal
    />
  );
}
