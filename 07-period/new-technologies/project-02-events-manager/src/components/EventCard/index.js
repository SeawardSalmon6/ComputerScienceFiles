import { Animated, Image, Pressable, Text, View } from "react-native";
import { styles } from "./styles";
import { useTimingAnimation } from "../../hooks/useTimingAnimation";
import { useAnimations } from "../../hooks/useAnimations";
import { useScalingAnimation } from "../../hooks/useScalingAnimation";
import dayjs from "dayjs";
import Icon from "react-native-vector-icons/Octicons";
import { useEventsContext } from "../../contexts/Events/useEventsContext";
import { AppTheme } from "../../App.theme";
import { Empty } from "./Empty";
import { useAppNavigation } from "../../hooks/useAppNavigation";

function EventCard({ event, containerStyle, onPress, showEditAction = false }) {
  const { eventsDispatcher } = useEventsContext();
  const { goTo } = useAppNavigation();
  const { animations, onEnd, onStart } = useAnimations(
    useTimingAnimation(),
    useScalingAnimation()
  );

  if (!event) {
    return null;
  }

  const { date, image, location, title, available } = event;

  return (
    <Animated.View style={animations}>
      <Pressable
        style={[styles.container, containerStyle]}
        onPressIn={onStart}
        onPressOut={onEnd}
      >
        <Image
          style={styles.image}
          source={
            typeof image === "string"
              ? { uri: image, height: styles.image.height }
              : image
          }
          resizeMode="cover"
        />
        <View style={styles.contentContainer}>
          <View style={styles.infoContainer}>
            <View style={styles.dateContainer}>
              <Text style={styles.date}>
                {dayjs(date).format("DD/MM/YYYY")}
              </Text>
              {event.id && (
                <View style={styles.actionsContainer}>
                  <Pressable
                    onPress={() => {
                      eventsDispatcher({
                        type: "favorite",
                        payload: {
                          id: event.id,
                        },
                      });
                    }}
                    style={styles.actionContainer}
                  >
                    <Icon
                      name={event.favorite ? "bookmark-slash" : "bookmark"}
                      style={styles.icon}
                      color={event.favorite ? AppTheme.accent : AppTheme.text}
                    />
                  </Pressable>
                  {showEditAction && (
                    <Pressable
                      onPress={() => {
                        goTo("EditEvent", { event });
                      }}
                      style={styles.actionContainer}
                    >
                      <Icon
                        name={"pencil"}
                        style={styles.icon}
                        color={AppTheme.text}
                      />
                    </Pressable>
                  )}
                </View>
              )}
            </View>
            <Text style={styles.title}>{title}</Text>
            <Text style={styles.location}>{location}</Text>
          </View>
          <View style={styles.tagsContainer}>
            {available > 0 ? (
              <>
                <Text style={[styles.tag, styles["availableTickets"]]}>
                  {`só restam ${available} ingressos`}
                </Text>
                <Text style={[styles.tag, styles["available"]]}>
                  Disponível
                </Text>
              </>
            ) : (
              <Text style={[styles.tag, styles["soldOut"]]}>Esgotado</Text>
            )}
          </View>
        </View>
      </Pressable>
    </Animated.View>
  );
}

EventCard.Empty = Empty;

export { EventCard };
