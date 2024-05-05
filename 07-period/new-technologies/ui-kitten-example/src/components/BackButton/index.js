import { Icon, TopNavigationAction } from "@ui-kitten/components";
import { useAppNavigation } from "../../hooks/useAppNavigation";

export function BackButton({ backTo, ...props }) {
  const { goTo, goBack, canGoBack } = useAppNavigation();

  if (backTo === null && !canGoBack()) {
    return null;
  }

  return (
    <TopNavigationAction
      icon={<Icon name="arrow-back" />}
      onPress={() => {
        if (typeof backTo === "string") {
          goTo(backTo);
        } else if (typeof backTo === "function") {
          backTo();
        } else {
          goBack();
        }
      }}
      {...props}
    />
  );
}
