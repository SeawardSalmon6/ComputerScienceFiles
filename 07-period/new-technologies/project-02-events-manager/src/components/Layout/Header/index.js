import { Text, View } from "react-native";
import { styles } from "./styles";
import Icon from "react-native-vector-icons/Octicons";
import { ACTIONS_ICONS } from "./constants";
import { AnimatedButton } from "../../AnimatedButton";
import { useAppNavigation } from "../../../hooks/useAppNavigation";

export function Header({ backTo, children, title, actions = {} }) {
  const { getGoTo } = useAppNavigation();
  const actionsEntries = Object.entries(actions);

  return (
    <View style={styles.container}>
      <View style={styles.topBar}>
        <View style={styles.titleContainer}>
          {backTo && (
            <AnimatedButton
              onPress={getGoTo(backTo)}
              style={styles.actionButton}
            >
              <Icon name={ACTIONS_ICONS["back"]} style={styles.icon} />
            </AnimatedButton>
          )}
          <Text style={styles.title}>{title}</Text>
        </View>
        {actionsEntries.length > 0 && (
          <View style={styles.actionsContainer}>
            {actionsEntries.map(([action, callback]) => (
              <AnimatedButton
                key={action}
                style={styles.actionButton}
                onPress={callback}
              >
                <Icon name={ACTIONS_ICONS[action]} style={styles.icon} />
              </AnimatedButton>
            ))}
          </View>
        )}
      </View>
      {children}
    </View>
  );
}
